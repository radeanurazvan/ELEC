#include "Resistor.h"
#include "Resources/ResistorResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"


Resistor::Resistor()
{
}

void Resistor::Draw() {
	auto referencePoint = GetReferencePoint();

	const CartesianPoint bottomLeft(referencePoint.GetX(), referencePoint.GetY());
	const CartesianPoint topRight(referencePoint.GetX(), referencePoint.GetY());

GraphicsHelper::DrawRectangle(bottomLeft,topRight,ResistorResources::figureHeight,ResistorResources::figureWidth);
	auto LeftConductor = bottomLeft;
	auto RightConductor = topRight;
		RightConductor.MoveToRight(ResistorResources::figureWidth);
		LeftConductor.MoveUpwards(ResistorResources::figureHeight /2 );
		RightConductor.MoveUpwards(ResistorResources::figureHeight / 2 );
	DrawMiddleConnectors(LeftConductor,RightConductor );

}
