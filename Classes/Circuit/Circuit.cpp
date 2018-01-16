#include "Circuit.h"
#include "../Factories/ComponentFactory/ComponentFactory.h"
#include "../Helpers/CircuitReader/CircuitReader.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"

Circuit::Circuit()
{
}

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
	for (auto link : links)
	{
		DrawLinkBetween(link);
	}
}

void Circuit::DrawLinkBetween(
	JsonObjects::Link link)
{
	auto firstComponent = GetComponentById(link.FirstComponent);
	auto secondComponent = GetComponentById(link.SecondComponent);
	auto firstComponentConnector = firstComponent->GetConnector(link.FirstComponentConnector);
	auto secondComponentConnector = secondComponent->GetConnector(link.SecondComponentConnector);

	auto inflectionPointX = firstComponentConnector.GetX();
	auto inflectionPointY = secondComponentConnector.GetY();

	if (link.Type == UpwardsOriented)
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
		if (component->IsClicked(click))
		{
			return component;
		}
	}
	return nullptr;
}

BaseComponent* Circuit::GetComponentById(std::string id)
{
	for (auto component : components)
	{
		if (component->GetId() == id)
		{
			return component;
		}
	}
	return nullptr;
}

int Circuit::GetComponentIndexById(std::string id)
{
	for (auto componentIndex = 0; componentIndex < components.size(); componentIndex++)
	{
		auto component = components.at(componentIndex);
		if (component->GetId() == id)
		{
			return componentIndex;
		}
	}
	return -1;
}

std::string Circuit::GetClickedComponentId(MouseClickPoint click)
{
	for (int index = 0; index < components.size(); index++)
	{
		auto component = components.at(index);
		if (component->IsClicked(click))
		{
			return component->GetId();
		}
	}
	return "";
}

void Circuit::SetMaximumViewport()
{
	SetViewPort(GraphicsHelper::GetMaximumViewPort());
}

void Circuit::RefreshViewPort()
{
	GraphicsHelper::SetViewPort(viewPort);
	GraphicsHelper::ClearViewPort();
	GraphicsHelper::ResetViewPort();
}

void Circuit::RemoveComponentLinks(std::string componentId)
{
	links.erase(
		std::remove_if(
			links.begin(),
			links.end(),
			[&](JsonObjects::Link element) -> bool
			{
				return element.BelongsTo(componentId);
			}
		),
		links.end()
	);
}

void Circuit::Draw()
{
	RefreshViewPort();

	DrawComponents();
	DrawLinks();
}

void Circuit::LoadFromFile(char* fileName)
{
	auto circuit = CircuitReader::ReadFromJSON(fileName);
	Initialise(circuit);
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

void Circuit::RemoveComponent(std::string componentId)
{
	RemoveComponentLinks(componentId);
	auto componentIndex = GetComponentIndexById(componentId);
	components.erase(components.begin() + componentIndex);
	Draw();
}

void Circuit::RepositionComponent(std::string componentId, CartesianPoint newPoint)
{
	auto component = GetComponentById(componentId);
	auto coordinates = CartesianCoordinate(newPoint.GetX() - 10, newPoint.GetY() - 10);
	component->SetCoordinates(coordinates);
	Draw();
}

void Circuit::MoveComponent(std::string componentId, MouseClickPoint clickPoint)
{
	auto component = GetComponentById(componentId);
	component->MoveByClick(clickPoint.Point);
	Draw();
}

bool Circuit::ComponentsOverlap(BaseComponent* component)
{
	for (auto circuitComponent : components)
	{
		if (circuitComponent->GetContainerArea()->Overlaps(*component->GetContainerArea()))
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
	if (clickedConnectorDetails.IsValid())
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
	for (auto component : components)
	{
		auto connectors = component->GetConnectors();
		for (int connectorIndex = 0; connectorIndex < connectors.size(); connectorIndex++)
		{
			auto connector = connectors.at(connectorIndex);
			auto connectorAreaBottomLeft = CartesianPoint(connector.GetX() - BaseComponentResources::connectorErrorMargin,
			                                              connector.GetY() - BaseComponentResources::connectorErrorMargin);
			auto connectorAreaTopRight = CartesianPoint(connector.GetX() + BaseComponentResources::connectorErrorMargin,
			                                            connector.GetY() + BaseComponentResources::connectorErrorMargin);

			if (Area::RectangleArea(connectorAreaBottomLeft, connectorAreaTopRight)->Contains(clickPoint))
			{
				return ClickedConnectorDetails(component->GetId(), connectorIndex + 1);
			}
		}
	}

	return ClickedConnectorDetails::InvalidClick();
}
