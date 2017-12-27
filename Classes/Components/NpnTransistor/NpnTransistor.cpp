#include "NpnTransistor.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NpnTransistorResources.h"

NpnTransistor::NpnTransistor()
{
	
};


void NpnTransistor::Draw()
{
	const auto StartPoint = GetReferencePoint();
	GraphicsHelper::DrawCircle(StartPoint, NpnTransistorResources::Radius);
	
	auto UpperConductor = StartPoint;
		UpperConductor.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		UpperConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	auto LowerConductor = StartPoint;
		LowerConductor.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		LowerConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	auto MidConductor = StartPoint;
		MidConductor.MoveToRight(-NpnTransistorResources::DistanceFromMidPoint);
		MidConductor.MoveDownwards(NpnTransistorResources::Radius);
	auto MidLine = MidConductor;
		MidLine.MoveUpwards(NpnTransistorResources::Height);
	GraphicsHelper::DrawLine(MidConductor,MidLine);
		
		MidConductor.MoveUpwards(NpnTransistorResources::Radius);
	auto Line = MidConductor;
		Line.MoveToRight(-NpnTransistorResources::Lenght);
	GraphicsHelper::DrawLine(MidConductor, Line);
	GraphicsHelper::DrawLine(MidConductor, UpperConductor);
	GraphicsHelper::DrawLine(MidConductor, LowerConductor);
	
	auto PointA = LowerConductor;
	auto PointB = LowerConductor;
	auto PointC = LowerConductor;
		PointA.MoveDownwards(NpnTransistorResources::DistanceFromaPoint);
		PointB.MoveToRight(-NpnTransistorResources::DistanceFromaPoint);
	auto UpperLine = UpperConductor;
		UpperLine.MoveDownwards(NpnTransistorResources::EntriLine);
	GraphicsHelper::DrawTriangle(PointA, PointB, PointC);
	GraphicsHelper::DrawLine(UpperConductor, UpperLine);
}
