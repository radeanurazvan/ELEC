#include "ZennerDiode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/ZennerDiodeResources.h"

ZennerDiode::ZennerDiode()
{
}

void ZennerDiode::Draw()
{
	const auto ConductorPoint = GetReferencePoint();
	auto StartUpDrawPoint = ConductorPoint;
	auto StartDownDrawPoint = ConductorPoint;
	auto ConductorPointLine = ConductorPoint;
		ConductorPointLine.MoveUpwards(ZennerDiodeResources::ConductorHeight);
	GraphicsHelper::DrawLine(ConductorPoint, ConductorPointLine);
	
	auto EndConductorPoint = ConductorPoint;
	auto UpperConductor = StartUpDrawPoint;
		UpperConductor.MoveToRight(-ZennerDiodeResources::ConductorCurve);
		UpperConductor.MoveDownwards(ZennerDiodeResources::ConductorCurveHeight);
	GraphicsHelper::DrawLine(StartUpDrawPoint, UpperConductor);
	
		StartDownDrawPoint.MoveUpwards(ZennerDiodeResources::ConductorHeight);
	auto LowerConductor = StartDownDrawPoint;
		LowerConductor.MoveUpwards(ZennerDiodeResources::ConductorCurveHeight);
		LowerConductor.MoveToRight(ZennerDiodeResources::ConductorCurve);
	GraphicsHelper::DrawLine(StartDownDrawPoint, LowerConductor);
	
		EndConductorPoint.MoveToRight(ZennerDiodeResources::TriangleWidth);
	auto PointA = ConductorPoint;
	auto PointB = EndConductorPoint;
	auto PointC = EndConductorPoint;
		PointA.MoveUpwards(ZennerDiodeResources::ConductorHeight / 2);
		PointB.MoveUpwards(ZennerDiodeResources::ConductorHeight);
		PointC.MoveDownwards(ZennerDiodeResources::ConductorHeight / 4);
	GraphicsHelper::DrawTriangle(PointA, PointB, PointC);
	
		EndConductorPoint.MoveUpwards(ZennerDiodeResources::ConductorHeight);
		DrawMiddleConnectors(ConductorPoint, EndConductorPoint);
}
