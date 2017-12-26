#include "Resistor.h"
#include "Resources/ResistorResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"


Resistor::Resistor()
{
}

void Resistor::Draw() {
	auto referencePoint = GetReferencePoint();

	const CartesianPoint bottomLeft(referencePoint.GetX(), referencePoint.GetY());
	const CartesianPoint topRight(referencePoint.GetX() +  ResistorResources::figureWidth, referencePoint.GetY() + ResistorResources::figureHeight);

	GraphicsHelper::DrawRectangle(bottomLeft, topRight);
	DrawMiddleConnectors(bottomLeft, topRight);

}
