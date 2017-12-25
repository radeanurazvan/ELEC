#include "PnpTransistor.h"
#include "../../Classes/Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/PnpTransistorResources.h"

PnpTransistor::PnpTransistor()
{
}

void PnpTransistor::Draw()
{
	const auto StartPoint = GetReferencePoint();
	GraphicsHelper::DrawCircle(StartPoint, PnpTransistorResources::Radius);
	auto UpperConductor = StartPoint;
	UpperConductor.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors);
	UpperConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
	auto LowerConductor = StartPoint;
	LowerConductor.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors);
	LowerConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
	auto MidConductor = StartPoint;
	MidConductor.MoveToRight(-PnpTransistorResources::DistanceFromMidPoint);
	MidConductor.MoveDownwards(PnpTransistorResources::Radius);
	GraphicsHelper::DrawSegmnentOfHeight(MidConductor, PnpTransistorResources::Height);
	MidConductor.MoveUpwards(PnpTransistorResources::Radius);
	auto Line = MidConductor;
	Line.MoveToRight(-PnpTransistorResources::Lenght);
	GraphicsHelper::DrawLine(MidConductor, Line);
	GraphicsHelper::DrawLine(MidConductor, UpperConductor);
	GraphicsHelper::DrawLine(MidConductor, LowerConductor);
	auto PointC = UpperConductor;
	PointC.MoveToRight(PnpTransistorResources::EntriLine);
	PointC.MoveDownwards(PnpTransistorResources::EntriLine);
	auto PointA = PointC;
	auto PointB = PointC;
	PointA.MoveUpwards(PnpTransistorResources::DistanceFromaPoint);
	PointB.MoveToRight(-PnpTransistorResources::DistanceFromaPoint);
	GraphicsHelper::DrawTriangle(PointA, PointB, PointC);
	GraphicsHelper::DrawSegmnentOfHeight(LowerConductor, PnpTransistorResources::EntriLine);
}
