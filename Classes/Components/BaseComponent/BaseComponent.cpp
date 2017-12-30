#include "BaseComponent.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/BaseComponentResources.h"


void BaseComponent::DrawConnectorLines(CartesianPoint leftStart, CartesianPoint leftEnd, CartesianPoint rightStart,
	CartesianPoint rightEnd)
{
	GraphicsHelper::DrawLine(leftStart, leftEnd);
	GraphicsHelper::DrawLine(rightStart, rightEnd);

	connectorPoints.push_back(CartesianPoint(leftEnd.GetX(), leftEnd.GetY()));
	connectorPoints.push_back(CartesianPoint(rightEnd.GetX(), rightEnd.GetY()));
}

void BaseComponent::DrawMiddleConnectors(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit)
{

	const CartesianPoint topLeft(bottomLeftLimit.GetX(), topRightLimit.GetY());
	const CartesianPoint bottomRight(topRightLimit.GetX(), bottomLeftLimit.GetY());

	const auto middleLeft = CartesianPointsHelper::GetMiddlePointBetween(topLeft, bottomLeftLimit);
	const auto middleRight = CartesianPointsHelper::GetMiddlePointBetween(topRightLimit, bottomRight);
	auto middleLeftLine = middleLeft;
	auto middleRightLine = middleRight;
		middleLeftLine.MoveToLeft(BaseComponentResources::connectorWidth);
	middleRightLine.MoveToRight(BaseComponentResources::connectorWidth);
	DrawConnectorLines(middleLeft, middleLeftLine, middleRight, middleRightLine);
}

void BaseComponent::DrawMiddleConnectors90Degrees(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit)
{

	const CartesianPoint topLeft(bottomLeftLimit.GetX(), bottomLeftLimit.GetY());
	const CartesianPoint bottomRight(topRightLimit.GetX(), topRightLimit.GetY());

	const auto middleLeft = CartesianPointsHelper::GetMiddlePointBetween(topLeft, bottomLeftLimit);
	const auto middleRight = CartesianPointsHelper::GetMiddlePointBetween(topRightLimit, bottomRight);
	auto middleLeftLine = middleLeft;
	auto middleRightLine = middleRight;
	middleLeftLine.MoveUpwards(BaseComponentResources::connectorWidth);
	middleRightLine.MoveDownwards(BaseComponentResources::connectorWidth);
	DrawConnectorLines(middleLeft, middleLeftLine, middleRight, middleRightLine);

}
CartesianPoint BaseComponent::GetReferencePoint()
{
	return CartesianPoint (GetCoordinates().GetX(), GetCoordinates().GetY());
}

void BaseComponent::PushConnectorPoint(CartesianPoint connectorPoint)
{
	connectorPoints.push_back(connectorPoint);
}

BaseComponent::BaseComponent(): coordinates()
{
	numberOfConnectors = 0;
	name = "Base Component";
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

CartesianPoint BaseComponent::GetConnector(int index)
{
	return connectorPoints.at(index-1);
}


