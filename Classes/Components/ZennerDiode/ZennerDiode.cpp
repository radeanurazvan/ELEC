#include "ZennerDiode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/ZennerDiodeResources.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"

ZennerDiode::ZennerDiode()
	: BaseComponent(ZennerDiodeResources::ActualContainerSize)
{
	SetName(name);
}

void ZennerDiode::Draw()
{
	const auto conductorPoint = GetReferencePoint();
	auto startUpDrawPoint = conductorPoint;
	auto startDownDrawPoint = conductorPoint;
	auto conductorPointLine = conductorPoint;
	auto endConductorPoint = conductorPoint;
	auto upperConductor = startUpDrawPoint;
	auto lowerConductor = startDownDrawPoint;
	auto pointA = conductorPoint;
	auto pointB = endConductorPoint;
	auto pointC = endConductorPoint;
		
	if (orientation == Normal)
	{
		conductorPointLine.MoveUpwards(ZennerDiodeResources::ConductorHeight);

		upperConductor
			.MoveToLeft(ZennerDiodeResources::ConductorCurve)
				->MoveDownwards(ZennerDiodeResources::ConductorCurveHeight);

		startDownDrawPoint.MoveUpwards(ZennerDiodeResources::ConductorHeight);

		lowerConductor
			.MoveUpwards(ZennerDiodeResources::ConductorCurveHeight + ZennerDiodeResources::ConductorHeight)
				->MoveToRight(ZennerDiodeResources::ConductorCurve);

		endConductorPoint
			.MoveToRight(ZennerDiodeResources::TriangleWidth);
			
		pointA.MoveUpwards(ZennerDiodeResources::ConductorHeight / 2);
		pointB
			.MoveUpwards(ZennerDiodeResources::ConductorHeight)
				->MoveToRight(ZennerDiodeResources::TriangleWidth);
		pointC
			.MoveDownwards(ZennerDiodeResources::ConductorHeight / 4)
				->MoveToRight(ZennerDiodeResources::TriangleWidth);

		endConductorPoint.MoveUpwards(ZennerDiodeResources::ConductorHeight);
		
	}
	else
	if(orientation == Degrees90)
	{
		conductorPointLine.MoveToRight(ZennerDiodeResources::ConductorHeight);

		upperConductor
			.MoveUpwards(ZennerDiodeResources::ConductorCurve)
				->MoveToLeft(ZennerDiodeResources::ConductorCurveHeight);

		startDownDrawPoint.MoveToRight(ZennerDiodeResources::ConductorHeight);

		lowerConductor
			.MoveToRight(ZennerDiodeResources::ConductorCurveHeight + ZennerDiodeResources::ConductorHeight)
				->MoveDownwards(ZennerDiodeResources::ConductorCurve);

		endConductorPoint
			.MoveDownwards(ZennerDiodeResources::TriangleWidth);

		pointA.MoveToRight(ZennerDiodeResources::ConductorHeight / 2);
		pointB
			.MoveToRight(ZennerDiodeResources::ConductorHeight)
				->MoveDownwards(ZennerDiodeResources::TriangleWidth);
		pointC
			.MoveToLeft(ZennerDiodeResources::ConductorHeight / 4)
				->MoveDownwards(ZennerDiodeResources::TriangleWidth);

		endConductorPoint.MoveToRight(ZennerDiodeResources::ConductorHeight);

		
	}
	else
	if(orientation == Degrees180)
	{
		conductorPointLine.MoveDownwards(ZennerDiodeResources::ConductorHeight);

		upperConductor
			.MoveToRight(ZennerDiodeResources::ConductorCurve)
				->MoveUpwards(ZennerDiodeResources::ConductorCurveHeight);

		startDownDrawPoint.MoveDownwards(ZennerDiodeResources::ConductorHeight);

		lowerConductor
			.MoveDownwards(ZennerDiodeResources::ConductorCurveHeight + ZennerDiodeResources::ConductorHeight)
				->MoveToLeft(ZennerDiodeResources::ConductorCurve);

		endConductorPoint
			.MoveToLeft(ZennerDiodeResources::TriangleWidth);

		pointA.MoveDownwards(ZennerDiodeResources::ConductorHeight / 2);
		pointB
			.MoveDownwards(ZennerDiodeResources::ConductorHeight)
				->MoveToLeft(ZennerDiodeResources::TriangleWidth);
		pointC
			.MoveUpwards(ZennerDiodeResources::ConductorHeight / 4)
				->MoveToLeft(ZennerDiodeResources::TriangleWidth);

		endConductorPoint.MoveDownwards(ZennerDiodeResources::ConductorHeight);
	}
	else
	if(orientation == Degrees270)
	{
		conductorPointLine.MoveToLeft(ZennerDiodeResources::ConductorHeight);

		upperConductor
			.MoveDownwards(ZennerDiodeResources::ConductorCurve)
				->MoveToRight(ZennerDiodeResources::ConductorCurveHeight);

		startDownDrawPoint.MoveToLeft(ZennerDiodeResources::ConductorHeight);

		lowerConductor
			.MoveToLeft(ZennerDiodeResources::ConductorCurveHeight + ZennerDiodeResources::ConductorHeight)
				->MoveUpwards(ZennerDiodeResources::ConductorCurve);

		endConductorPoint
			.MoveUpwards(ZennerDiodeResources::TriangleWidth);

		pointA.MoveToLeft(ZennerDiodeResources::ConductorHeight / 2);
		pointB
			.MoveToLeft(ZennerDiodeResources::ConductorHeight)
				->MoveUpwards(ZennerDiodeResources::TriangleWidth);
		pointC
			.MoveToRight(ZennerDiodeResources::ConductorHeight / 4)
				->MoveUpwards(ZennerDiodeResources::TriangleWidth);

		endConductorPoint.MoveToLeft(ZennerDiodeResources::ConductorHeight);
	}
	
	GraphicsHelper::DrawLine(conductorPoint, conductorPointLine);
	GraphicsHelper::DrawLine(startUpDrawPoint, upperConductor);
	GraphicsHelper::DrawLine(startDownDrawPoint, lowerConductor);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);

	if(orientation == Normal)
		DrawMiddleConnectors(conductorPoint, endConductorPoint);
	else
	if(orientation == Degrees180)
		DrawMiddleConnectors(endConductorPoint, conductorPoint);
	else
	{
		auto startConductorPoint = pointA;
		auto endConductPoint = pointB;
		if (orientation == Degrees90)
		{
			endConductorPoint.MoveToLeft(ZennerDiodeResources::ConductorHeight / 2);
			DrawMiddleConnectors90Degrees(startConductorPoint, endConductorPoint);
		}
		else
		{		
			endConductorPoint.MoveToRight(ZennerDiodeResources::ConductorHeight / 2);
			DrawMiddleConnectors90Degrees(endConductorPoint, startConductorPoint);
		}
	}
	
		
}
