#include "BaseComponent.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/BaseComponentResources.h"
#include "../../Guid/Guid.h"


void BaseComponent::DrawConnectorLines(CartesianPoint leftStart, CartesianPoint leftEnd, CartesianPoint rightStart,
	CartesianPoint rightEnd)
{
	GraphicsHelper::DrawLine(leftStart, leftEnd);
	GraphicsHelper::DrawLine(rightStart, rightEnd);

	connectorPoints.clear();
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

	const CartesianPoint topLeft(topRightLimit.GetX(), bottomLeftLimit.GetY());
	const CartesianPoint bottomRight(bottomLeftLimit.GetX(), topRightLimit.GetY());

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
	auto containerPadding = (resources.maxContainerSize - resources.actualContainerSize) / 2;
	return CartesianPoint (GetCoordinates().GetX() + containerPadding, GetCoordinates().GetY() + containerPadding);
}

void BaseComponent::PushConnectorPoint(CartesianPoint connectorPoint)
{
	connectorPoints.push_back(connectorPoint);
}

bool BaseComponent::IsTopClicked(CartesianPoint clickPoint)
{
	auto area = GetContainerArea();
	auto topRight = area->GetTopRight();

	auto bottomLeft = area->GetBottomLeft();
	topRight.SetCoordinates(CartesianCoordinate(bottomLeft.GetX(), topRight.GetY()));

	auto middlePoint = CartesianPointsHelper::GetMiddlePointBetween(bottomLeft, topRight);
	
	return Area::RectangleArea(middlePoint, area->GetTopRight())->Contains(clickPoint);
}

bool BaseComponent::IsBottomClicked(CartesianPoint clickPoint)
{
	auto area = GetContainerArea();
	auto topRight = area->GetTopRight();

	auto bottomLeft = area->GetBottomLeft();
	bottomLeft.SetCoordinates(CartesianCoordinate(topRight.GetX(), bottomLeft.GetY()));

	auto middlePoint = CartesianPointsHelper::GetMiddlePointBetween(bottomLeft, topRight);

	return Area::RectangleArea(area->GetBottomLeft(), middlePoint)->Contains(clickPoint);
}

bool BaseComponent::IsLeftClicked(CartesianPoint clickPoint)
{
	auto area = GetContainerArea();
	auto topRight = area->GetTopRight();

	auto bottomLeft = area->GetBottomLeft();
	topRight.SetCoordinates(CartesianCoordinate(bottomLeft.GetX(), topRight.GetY()));
	topRight.MoveToRight(BaseComponentResources::connectorWidth);

	return Area::RectangleArea(bottomLeft, topRight)->Contains(clickPoint);
}

bool BaseComponent::IsRightClicked(CartesianPoint clickPoint)
{
	auto area = GetContainerArea();
	auto topRight = area->GetTopRight();

	auto bottomLeft = area->GetBottomLeft();
	bottomLeft.SetCoordinates(CartesianCoordinate(topRight.GetX(), bottomLeft.GetY()));
	bottomLeft.MoveToLeft(BaseComponentResources::connectorWidth);

	return Area::RectangleArea(bottomLeft, topRight)->Contains(clickPoint);
}

BaseComponent::BaseComponent(const int actualContainerSize): coordinates()
{
	id = Guid::NewGuid();
	numberOfConnectors = 0;
	orientation = Normal;
	resources.actualContainerSize = actualContainerSize;
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
	return this->name;
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

void BaseComponent::SetOrientation(::Orientation _orientation)
{
	orientation = _orientation;
}

CartesianPoint BaseComponent::GetConnector(int index)
{
	return connectorPoints.at(index-1);
}

std::vector<CartesianPoint> BaseComponent::GetConnectors()
{
	return connectorPoints;
}

Area* BaseComponent::GetContainerArea()
{
	auto bottomLeft = CartesianPoint(coordinates.GetX(), coordinates.GetY());
	auto topRight = CartesianPoint(coordinates.GetX() + resources.maxContainerSize, coordinates.GetY() + resources.maxContainerSize);
	return Area::RectangleArea(bottomLeft, topRight);
}

bool BaseComponent::IsClicked(MouseClickPoint click)
{
	return GetContainerArea()->Contains(click.Point);
}

void BaseComponent::Rotate()
{
	int currentOrientation = orientation;
	auto nextOrientation = currentOrientation % 4 + 1;
	orientation = static_cast<Orientation>(nextOrientation);
	connectorPoints.clear();
}

std::string BaseComponent::GetId()
{
	return id;
}

void BaseComponent::SetId(std::string guid)
{
	id = guid;
}

void BaseComponent::MoveByClick(CartesianPoint clickPoint)
{
	if(IsTopClicked(clickPoint))
	{
		SetCoordinates(CartesianCoordinate(coordinates.GetX(), coordinates.GetY() - BaseComponentResources::connectorWidth));
	}
	if(IsBottomClicked(clickPoint))
	{
		SetCoordinates(CartesianCoordinate(coordinates.GetX(), coordinates.GetY() + BaseComponentResources::connectorWidth));
	}
	if(IsLeftClicked(clickPoint))
	{
		SetCoordinates(CartesianCoordinate(coordinates.GetX() + BaseComponentResources::connectorWidth, coordinates.GetY()));
	}
	if(IsRightClicked(clickPoint))
	{
		SetCoordinates(CartesianCoordinate(coordinates.GetX() - BaseComponentResources::connectorWidth, coordinates.GetY()));
	}
}

