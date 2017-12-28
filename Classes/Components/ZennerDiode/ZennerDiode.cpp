#include "ZennerDiode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/ZennerDiodeResources.h"

ZennerDiode::ZennerDiode()
{
}

void ZennerDiode::Draw()
{
	const auto conductorPoint = GetReferencePoint();
	auto startUpDrawPoint = conductorPoint;
	auto startDownDrawPoint = conductorPoint;
	auto conductorPointLine = conductorPoint;
		conductorPointLine.MoveUpwards(ZennerDiodeResources::ConductorHeight);
	GraphicsHelper::DrawLine(conductorPoint, conductorPointLine);
	
	auto endConductorPoint = conductorPoint;
	auto upperConductor = startUpDrawPoint;
		upperConductor.MoveToRight(-ZennerDiodeResources::ConductorCurve);
		upperConductor.MoveDownwards(ZennerDiodeResources::ConductorCurveHeight);
	GraphicsHelper::DrawLine(startUpDrawPoint, upperConductor);
	
		startDownDrawPoint.MoveUpwards(ZennerDiodeResources::ConductorHeight);
	auto lowerConductor = startDownDrawPoint;
		lowerConductor.MoveUpwards(ZennerDiodeResources::ConductorCurveHeight);
		lowerConductor.MoveToRight(ZennerDiodeResources::ConductorCurve);
	GraphicsHelper::DrawLine(startDownDrawPoint, lowerConductor);
	
		endConductorPoint.MoveToRight(ZennerDiodeResources::TriangleWidth);
	auto pointA = conductorPoint;
	auto pointB = endConductorPoint;
	auto pointC = endConductorPoint;
		pointA.MoveUpwards(ZennerDiodeResources::ConductorHeight / 2);
		pointB.MoveUpwards(ZennerDiodeResources::ConductorHeight);
		pointC.MoveDownwards(ZennerDiodeResources::ConductorHeight / 4);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	
		endConductorPoint.MoveUpwards(ZennerDiodeResources::ConductorHeight);
		DrawMiddleConnectors(conductorPoint, endConductorPoint);
}
