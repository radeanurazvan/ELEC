#include "Resistor.h"
#include "Resources/ResistorResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"


Resistor::Resistor()
{
	SetName(name);
}

void Resistor::Draw() {
	auto referencePoint = GetReferencePoint();
	auto LeftConductor = referencePoint;
	auto RightConductor = referencePoint;
	const CartesianPoint bottomLeft(referencePoint.GetX(), referencePoint.GetY());
	CartesianPoint topRight(referencePoint.GetX(), referencePoint.GetY());
	if (orientation == Normal || orientation == Degrees180)
	{
		auto topRightCoordinates = new CartesianCoordinate(
			referencePoint.GetX() + ResistorResources::figureWidth,
			referencePoint.GetY() + ResistorResources::figureHeight);
		topRight.SetCoordinates(*topRightCoordinates);	
		
			LeftConductor = bottomLeft;
			RightConductor = topRight;
			DrawMiddleConnectors(LeftConductor, RightConductor);
	}
	else
	{
		auto topRightCoordinates = new CartesianCoordinate(
			referencePoint.GetX() + ResistorResources::figureHeight,
			referencePoint.GetY() + ResistorResources::figureWidth);
		topRight.SetCoordinates(*topRightCoordinates);

		 LeftConductor = bottomLeft;
		 RightConductor = topRight;
		 DrawMiddleConnectors90Degrees(RightConductor, LeftConductor);
	}
	GraphicsHelper::DrawRectangle(bottomLeft, topRight);

	
}
