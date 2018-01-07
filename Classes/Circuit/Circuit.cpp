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

Circuit::Circuit()
{
}

void Circuit::DrawFromFile(char* fileName)
{
	GraphicsHelper::ClearScreen();
	std::vector<BaseComponent> circuitComponents;
	auto circuit = CircuitReader::ReadFromJSON(fileName);
	Initialise(circuit);
	DrawComponents();
	DrawLinks();
}
