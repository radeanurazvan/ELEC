#include "Resistor.h"
#include "Resources/ResistorResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"


Resistor::Resistor()
{
	SetName(name);
}

void Resistor::Draw() {
	auto referencePoint = GetReferencePoint();

	const CartesianPoint bottomLeft(referencePoint.GetX(), referencePoint.GetY());
	CartesianPoint topRight(referencePoint.GetX(), referencePoint.GetY());
	if (orientation == Normal)
	{
		auto topRightCoordinates = new CartesianCoordinate(
			referencePoint.GetX() + ResistorResources::figureWidth,
			referencePoint.GetY() + ResistorResources::figureHeight);
		topRight.SetCoordinates(*topRightCoordinates);

		GraphicsHelper::DrawRectangle(bottomLeft, topRight);
		auto LeftConductor = bottomLeft;
		auto RightConductor = topRight;
		DrawMiddleConnectors(LeftConductor, RightConductor);
	}
	
	
}
