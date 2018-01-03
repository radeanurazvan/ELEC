#include "Diode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources//DiodeResources.h"

Diode::Diode()
{
	SetName(name);
}

void Diode::Draw()
{
	const auto conductorPoint = GetReferencePoint();
	auto conductorPointLine = conductorPoint;
	auto endConductorPoint = conductorPoint;
	auto pointA = conductorPoint;
	auto pointB = endConductorPoint;
	auto pointC = endConductorPoint;
	if (orientation == Normal)
	{
		conductorPointLine.MoveUpwards(DiodeResources::ConductorHeight);

		endConductorPoint
			.MoveToRight(DiodeResources::TriangleWidth)
				->MoveUpwards(DiodeResources::ConductorHeight);

		pointA.MoveUpwards(DiodeResources::ConductorHeight / 2);

		pointB
			.MoveUpwards(DiodeResources::ConductorHeight)
				->MoveToRight(DiodeResources::TriangleWidth);

		pointC
			.MoveDownwards(DiodeResources::ConductorHeight / 4)
				->MoveToRight(DiodeResources::TriangleWidth);
		DrawMiddleConnectors(conductorPoint, endConductorPoint);
	}
	else
	if(orientation == Degrees90)
	{
		conductorPointLine.MoveToRight(DiodeResources::ConductorHeight);

		endConductorPoint
			.MoveDownwards(DiodeResources::TriangleWidth)
			->MoveToRight(DiodeResources::ConductorHeight);

		pointA.MoveToRight(DiodeResources::ConductorHeight / 2);
		pointB
			.MoveToRight(DiodeResources::ConductorHeight)
				->MoveDownwards(DiodeResources::TriangleWidth);

		pointC
			.MoveToLeft(DiodeResources::ConductorHeight / 4)
				->MoveDownwards(DiodeResources::TriangleWidth);
		DrawMiddleConnectors90Degrees(conductorPoint, endConductorPoint);
	}
	else
	if(orientation == Degrees180)
	{
		conductorPointLine.MoveDownwards(DiodeResources::ConductorHeight);

		endConductorPoint
			.MoveToLeft(DiodeResources::TriangleWidth)
				->MoveDownwards(DiodeResources::ConductorHeight);

		pointA.MoveDownwards(DiodeResources::ConductorHeight / 2);

		pointB
			.MoveDownwards(DiodeResources::ConductorHeight)
				->MoveToLeft(DiodeResources::TriangleWidth);

		pointC
			.MoveUpwards(DiodeResources::ConductorHeight / 4)
				->MoveToLeft(DiodeResources::TriangleWidth);
		DrawMiddleConnectors(endConductorPoint, conductorPoint);
	}
	else
	if(orientation == Degrees270)
	{
		conductorPointLine.MoveToLeft(DiodeResources::ConductorHeight);

		endConductorPoint
			.MoveUpwards(DiodeResources::TriangleWidth)
				->MoveToLeft(DiodeResources::ConductorHeight);

		pointA.MoveToLeft(DiodeResources::ConductorHeight / 2);

		pointB
			.MoveToLeft(DiodeResources::ConductorHeight)
				->MoveUpwards(DiodeResources::TriangleWidth);

		pointC
			.MoveToRight(DiodeResources::ConductorHeight / 4)
				->MoveUpwards(DiodeResources::TriangleWidth);
		DrawMiddleConnectors90Degrees(endConductorPoint, conductorPoint);
	}
	 GraphicsHelper::DrawLine(conductorPoint, conductorPointLine);
	 GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	 

}
