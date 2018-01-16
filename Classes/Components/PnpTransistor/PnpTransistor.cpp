#include "PnpTransistor.h"
#include "../../Classes/Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/PnpTransistorResources.h"
#include "../BaseComponent/Resources/BaseComponentResources.h"

CartesianPoint PnpTransistor::GetReferencePoint()
{
	auto referencePoint = BaseComponent::GetReferencePoint();
	referencePoint.MoveUpwards(BaseComponentResources::connectorWidth);
	referencePoint.MoveToRight(BaseComponentResources::connectorWidth);
	return  referencePoint;
}

PnpTransistor::PnpTransistor()
	: BaseComponent(PnpTransistorResources::ActualContainerSize)
{
	SetName(name);
}

void PnpTransistor::Draw()
{
	const auto startPoint = GetReferencePoint();
	auto upperConductor = startPoint;
	auto lowerConductor = startPoint;
	auto midConductor = startPoint;
	auto midLine = midConductor;
	auto midStartPoint = midLine;
	auto Line = midConductor;
	auto pointC = upperConductor;
	auto pointA = pointC;
	auto pointB = pointC;
	auto lowerLine = lowerConductor;
	auto upperStartPoint = upperConductor;
	auto lowerStartPoint = lowerConductor;
	
	if (orientation == Normal)
	{
		upperConductor
			.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors )
				->MoveToRight(PnpTransistorResources::DistanceFromMidPoint );

		lowerConductor
			.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		midLine
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::Radius);

		midStartPoint
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::Radius);

		lowerStartPoint
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::TriangleDistance);
		
		upperStartPoint
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::TriangleDistance);
		
		Line.MoveToLeft(BaseComponentResources::connectorWidth);

		pointC
			.MoveToRight(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveToRight(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors- PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveToRight(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint- PnpTransistorResources::DistanceFromaPoint)
				->MoveDownwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(orientation == Degrees90)
	{
		upperConductor
			.MoveToLeft(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor
		.MoveToRight(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);

		midLine
			.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint
			.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::Radius);

		lowerStartPoint
			.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::TriangleDistance);
		upperStartPoint
			.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::TriangleDistance);

		Line.MoveUpwards(BaseComponentResources::connectorWidth);

		pointC
			.MoveDownwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveDownwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveDownwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint)
				->MoveToLeft(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(orientation == Degrees180)
	{
		upperConductor
			.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		midLine
			.MoveToRight(PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint
			.MoveToRight(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::Radius);

		lowerStartPoint
			.MoveToRight(PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::TriangleDistance);
		upperStartPoint
			.MoveToRight(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::TriangleDistance);

		Line.MoveToRight(BaseComponentResources::connectorWidth);

		pointC
			.MoveToLeft(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveToLeft(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveToLeft(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint)
				->MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(orientation == Degrees270)
	{
		upperConductor
			.MoveToRight(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveToLeft(PnpTransistorResources::DistanceBetweenCondcutors)
			->MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);

		midLine
			.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint
			.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::Radius);

		lowerStartPoint
			.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::TriangleDistance);
		upperStartPoint
			.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::TriangleDistance);

		Line.MoveDownwards(BaseComponentResources::connectorWidth);

		pointC
			.MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveUpwards(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint)
				->MoveToRight(PnpTransistorResources::TriangleDistance + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
	}
	GraphicsHelper::DrawCircle(startPoint, PnpTransistorResources::Radius);
	GraphicsHelper::DrawLine(midStartPoint, midLine);
	GraphicsHelper::DrawLine(midConductor, Line);
	GraphicsHelper::DrawLine(upperStartPoint, upperConductor); //// Linia din cerc spre Triunghi
	GraphicsHelper::DrawLine(lowerStartPoint, lowerConductor);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	GraphicsHelper::DrawLine(lowerConductor, lowerLine);

	connectorPoints.clear();
	PushConnectorPoint(pointC);
	PushConnectorPoint(Line);
	PushConnectorPoint(lowerLine);
}
