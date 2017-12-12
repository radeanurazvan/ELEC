#include "BaseComponent.h"



BaseComponent::BaseComponent()
{
	numberOfConnectors = 0;
	name = "Base Component";
}


BaseComponent::~BaseComponent()
{
	delete this;
}

int BaseComponent::GetNumberOfConnectors()
{
	return numberOfConnectors;
}

void BaseComponent::SetNumberOfConnectors(int number)
{
	numberOfConnectors = number;
}

std::string BaseComponent::GetName()
{
	return name;
}

void BaseComponent::SetName(std::string _name)
{
	name = _name;
}

CartesianCoordinate BaseComponent::GetCoordinates()
{
	return coordinates;
}

void BaseComponent::SetCoordinates(CartesianCoordinate coords)
{
	coordinates = coords;
}



