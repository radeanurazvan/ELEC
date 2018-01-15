#include "Circuit.h"
#include "../Factories/ComponentFactory/ComponentFactory.h"
#include "../Helpers/CircuitReader/CircuitReader.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"


void Circuit::Initialise(JsonObjects::CircuitDetails circuitDetails)
{
	components = std::vector<BaseComponent*>();
	links = std::vector<JsonObjects::Link>();
	for (const auto component : circuitDetails.Components)
	{
		auto instanceOfComponent = ComponentFactory::GetComponentByDetails(component);
		components.push_back(instanceOfComponent);
	}

	for (const auto link : circuitDetails.Links)
	{
		links.push_back(link);
	}
}

void Circuit::DrawComponents()
{
	for (auto component : components)
	{
		component->Draw();
	}
}

void Circuit::DrawLinks()
{
	for (const auto link : links)
	{
		DrawLinkBetween(link);
	}
}

void Circuit::DrawLinkBetween(
	JsonObjects::Link link)
{
	auto firstComponent = components.at(link.FirstComponent - 1);
	auto secondComponent = components.at(link.SecondComponent - 1);
	auto firstComponentConnector = firstComponent->GetConnector(link.FirstComponentConnector);
	auto secondComponentConnector = secondComponent->GetConnector(link.SecondComponentConnector);
	
	auto inflectionPointX = firstComponentConnector.GetX();
	auto inflectionPointY = secondComponentConnector.GetY();

	if(link.Type == UpwardsOriented)
	{
		inflectionPointX = secondComponentConnector.GetX();
		inflectionPointY = firstComponentConnector.GetY();
	}

	auto inflectionPoint = new CartesianPoint(inflectionPointX, inflectionPointY);
	GraphicsHelper::DrawLine(firstComponentConnector, *inflectionPoint);
	GraphicsHelper::DrawLine(*inflectionPoint, secondComponentConnector);
}

BaseComponent* Circuit::GetClickedComponent(MouseClickPoint click)
{
	for (auto component : components)
	{
		if(component->IsClicked(click))
		{
			return component;
		}
	}
	return nullptr;
}

void Circuit::RefreshViewPort()
{
	GraphicsHelper::SetViewPort(viewPort);
	GraphicsHelper::ClearViewPort();
	GraphicsHelper::ResetViewPort();
}

void Circuit::Draw()
{
	RefreshViewPort();

	DrawComponents();
	DrawLinks();
}

Circuit::Circuit()
{
}

void Circuit::DrawFromFile(char* fileName)
{
	auto circuit = CircuitReader::ReadFromJSON(fileName);
	Initialise(circuit);
	Draw();
}

void Circuit::AddComponent(BaseComponent* component)
{
	components.push_back(component);
}

void Circuit::AddLink(JsonObjects::Link link)
{
	links.push_back(link);
	Draw();
}

bool Circuit::ComponentsOverlap(BaseComponent* component)
{
	for (auto circuitComponent : components)
	{
		if(circuitComponent->GetContainerArea()->Overlaps(*component->GetContainerArea()))
		{
			return true;
		}
	}
	return false;
}

bool Circuit::IsComponentClicked(MouseClickPoint click)
{
	return GetClickedComponent(click) != nullptr ? true : false;
}

bool Circuit::IsClickedAroundConnector(MouseClickPoint click)
{
	auto clickedConnectorDetails = GetClickedConnectorDetails(click.Point);
	if(clickedConnectorDetails.IsValid())
	{
		return true;
	}
	return false;
}

void Circuit::RotateClickedComponent(MouseClickPoint click)
{
	auto clickedComponent = GetClickedComponent(click);
	clickedComponent->Rotate();
	Draw();
}

void Circuit::SetViewPort(Area* vp)
{
	viewPort = vp;
}

ClickedConnectorDetails Circuit::GetClickedConnectorDetails(CartesianPoint clickPoint)
{
	for (int componentIndex = 0; componentIndex < components.size(); componentIndex++)
	{
		auto component = components.at(componentIndex);
		auto connectors = component->GetConnectors();
		for (int connectorIndex = 0; connectorIndex < connectors.size(); connectorIndex++)
		{
			auto connector = connectors.at(connectorIndex);
			auto connectorAreaBottomLeft = CartesianPoint(connector.GetX() - BaseComponentResources::connectorErrorMargin, connector.GetY() - BaseComponentResources::connectorErrorMargin);
			auto connectorAreaTopRight = CartesianPoint(connector.GetX() + BaseComponentResources::connectorErrorMargin, connector.GetY() + BaseComponentResources::connectorErrorMargin);

			if (Area::RectangleArea(connectorAreaBottomLeft, connectorAreaTopRight)->Contains(clickPoint))
			{
				return ClickedConnectorDetails(componentIndex + 1, connectorIndex + 1);
			}
		}
	}

	return ClickedConnectorDetails::InvalidClick();
}
