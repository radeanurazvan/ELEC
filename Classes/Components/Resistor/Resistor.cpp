#include "Resistor.h"
#include ".././../Classes/Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/ResistorResources.h"


Resistor::Resistor()
{
}

void Resistor::Draw() {
	CartesianPoint referencePoint(GetCoordinates().GetX(), GetCoordinates().GetY());

	CartesianPoint bottomLeft(referencePoint.GetX(), referencePoint.GetY());
	CartesianPoint topRight(referencePoint.GetX() +  ResistorResources::figureWidth, referencePoint.GetY() + ResistorResources::figureHeight);

	GraphicsHelper::DrawRectangle(bottomLeft, topRight);

	const CartesianPoint topLeft(bottomLeft.GetX(), topRight.GetY());
	const CartesianPoint bottomRight(topRight.GetX(), bottomLeft.GetY());

	const auto middleLeft = CartesianPointsHelper::GetMiddlePointBetween(topLeft, bottomLeft);
	const auto middleRight = CartesianPointsHelper::GetMiddlePointBetween(topRight, bottomRight);

	GraphicsHelper::DrawSegmnentOfWidth(middleLeft, -BaseComponentResources::connectorWidth);
	GraphicsHelper::DrawSegmnentOfWidth(middleRight, BaseComponentResources::connectorWidth);

}
