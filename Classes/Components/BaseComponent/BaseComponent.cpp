#include "BaseComponent.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/BaseComponentResources.h"


void BaseComponent::DrawMiddleConnectors(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit)
{

	const CartesianPoint topLeft(bottomLeftLimit.GetX(), topRightLimit.GetY());
	const CartesianPoint bottomRight(topRightLimit.GetX(), bottomLeftLimit.GetY());

	const auto middleLeft = CartesianPointsHelper::GetMiddlePointBetween(topLeft, bottomLeftLimit);
	const auto middleRight = CartesianPointsHelper::GetMiddlePointBetween(topRightLimit, bottomRight);
	auto middleLeftLine = middleLeft;
	auto middleRightLine = middleRight;
		middleLeftLine.MoveToRight(-BaseComponentResources::connectorWidth);
	middleRightLine.MoveToRight(BaseComponentResources::connectorWidth);
	GraphicsHelper::DrawLine(middleLeft, middleLeftLine);
	GraphicsHelper::DrawLine(middleRight, middleRightLine);
}

CartesianPoint BaseComponent::GetReferencePoint()
{
	return CartesianPoint (GetCoordinates().GetX(), GetCoordinates().GetY());
}

BaseComponent::BaseComponent(): coordinates()
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

void BaseComponent::SetOrientation(::Orientation orientation)
{
	Orientation = orientation;
}


