#include "NpnTransistor.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NpnTransistorResources.h"

NpnTransistor::NpnTransistor()
{
	
};


void NpnTransistor::Draw()
{
	const auto startPoint = GetReferencePoint();
	GraphicsHelper::DrawCircle(startPoint, NpnTransistorResources::Radius);
	
	auto upperConductor = startPoint;
		upperConductor.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	auto lowerConductor = startPoint;
		lowerConductor.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	auto midConductor = startPoint;
		midConductor.MoveToRight(-NpnTransistorResources::DistanceFromMidPoint);
		midConductor.MoveDownwards(NpnTransistorResources::Radius);
	auto midLine = midConductor;
		midLine.MoveUpwards(NpnTransistorResources::Height);
	GraphicsHelper::DrawLine(midConductor,midLine);
		
		midConductor.MoveUpwards(NpnTransistorResources::Radius);
	auto Line = midConductor;
		Line.MoveToRight(-NpnTransistorResources::Lenght);
	GraphicsHelper::DrawLine(midConductor, Line);
	GraphicsHelper::DrawLine(midConductor, upperConductor);
	GraphicsHelper::DrawLine(midConductor, lowerConductor);
	
	auto PointA = lowerConductor;
	auto PointB = lowerConductor;
	auto PointC = lowerConductor;
		PointA.MoveDownwards(NpnTransistorResources::DistanceFromaPoint);
		PointB.MoveToRight(-NpnTransistorResources::DistanceFromaPoint);
	auto upperLine = upperConductor;
		upperLine.MoveDownwards(NpnTransistorResources::EntriLine);
	GraphicsHelper::DrawTriangle(PointA, PointB, PointC);
	GraphicsHelper::DrawLine(upperConductor, upperLine);
}
