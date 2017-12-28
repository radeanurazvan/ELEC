#include "PnpTransistor.h"
#include "../../Classes/Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/PnpTransistorResources.h"

PnpTransistor::PnpTransistor()
{
}

void PnpTransistor::Draw()
{
	const auto startPoint = GetReferencePoint();
	GraphicsHelper::DrawCircle(startPoint, PnpTransistorResources::Radius);
	
	
	auto upperConductor = startPoint;
		upperConductor.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);	
	auto lowerConductor = startPoint;
		lowerConductor.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);	
	auto midConductor = startPoint;
		midConductor.MoveToRight(-PnpTransistorResources::DistanceFromMidPoint);
		midConductor.MoveDownwards(PnpTransistorResources::Radius);
		auto midLine = midConductor;
		midLine.MoveUpwards(PnpTransistorResources::Height);
	GraphicsHelper::DrawLine(midConductor, midLine);
	
	midConductor.MoveUpwards(PnpTransistorResources::Radius);
	auto Line = midConductor;
		Line.MoveToRight(-PnpTransistorResources::Lenght);
	GraphicsHelper::DrawLine(midConductor, Line);
	GraphicsHelper::DrawLine(midConductor, upperConductor);
	GraphicsHelper::DrawLine(midConductor, lowerConductor);
	
	auto pointC = upperConductor;
		pointC.MoveToRight(PnpTransistorResources::EntriLine);
		pointC.MoveDownwards(PnpTransistorResources::EntriLine);
	auto pointA = pointC;
	auto pointB = pointC;
		pointA.MoveUpwards(PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveToRight(-PnpTransistorResources::DistanceFromaPoint);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	
	auto lowerLine = lowerConductor;
	lowerLine.MoveUpwards(PnpTransistorResources::EntriLine);
	GraphicsHelper::DrawLine(lowerConductor, lowerLine);
}
