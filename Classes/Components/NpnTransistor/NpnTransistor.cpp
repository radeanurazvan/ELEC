#include "NpnTransistor.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NpnTransistorResources.h"
#include "../BaseComponent/Resources/BaseComponentResources.h"

CartesianPoint NpnTransistor::GetReferencePoint()
{
	auto referencePoint = BaseComponent::GetReferencePoint();
	referencePoint.MoveUpwards(BaseComponentResources::connectorWidth);
	referencePoint.MoveToRight(BaseComponentResources::connectorWidth);
	return  referencePoint;
}

NpnTransistor::NpnTransistor()
	: BaseComponent(NpnTransistorResources::ActualContainerSize)
{
	SetName(name);
};


void NpnTransistor::Draw()
{
	const auto startPoint = GetReferencePoint();
	auto upperConductor = startPoint;
	auto lowerConductor = startPoint;
	auto midConductor = startPoint;
	auto midStartPoint = midConductor;
	auto midLine = midConductor;
	auto line = midConductor;
	auto lineStartPoint = line;
	auto pointA = lowerConductor;
	auto pointB = lowerConductor;
	auto pointC = lowerConductor;
	auto upperLine = upperConductor;
	auto upperStartPoint = upperConductor;
	auto lowerStartPoint = lowerConductor;
	
	
	if (orientation == Normal)
	{
		upperConductor
			.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint
			.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(NpnTransistorResources::Radius);

		midLine
			.MoveUpwards( NpnTransistorResources::Radius)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveToLeft(BaseComponentResources::connectorWidth);

		lowerStartPoint
			.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(NpnTransistorResources::EntriLine);
		upperStartPoint
			.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(NpnTransistorResources::EntriLine);

		pointA
			.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveToRight(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointB
			.MoveToRight(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance)
				->MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointC
			.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveToRight(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance);

		upperLine
			.MoveDownwards(NpnTransistorResources::TriangleDistance + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(orientation == Degrees90)
	{	
		upperConductor
			.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint
			.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(NpnTransistorResources::Radius);

		midLine
			.MoveToRight(NpnTransistorResources::Height - NpnTransistorResources::Radius)
				->MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveUpwards(BaseComponentResources::connectorWidth);

		lowerStartPoint
			.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToRight(NpnTransistorResources::EntriLine);

		upperStartPoint
			.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(NpnTransistorResources::EntriLine);

		pointA
			.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
					->MoveDownwards(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointB
			.MoveDownwards(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance)
				->MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointC
			.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveDownwards(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance);

		upperLine
			.MoveToLeft(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(orientation == Degrees180)
	{
		upperConductor
			.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint
			.MoveToRight(NpnTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(NpnTransistorResources::Radius);

		midLine
			.MoveDownwards(NpnTransistorResources::Height - NpnTransistorResources::Radius)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveToRight(BaseComponentResources::connectorWidth);

		lowerStartPoint
			.MoveToRight(NpnTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(NpnTransistorResources::EntriLine);
		upperStartPoint
			.MoveToRight(NpnTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(NpnTransistorResources::EntriLine);

		pointA
			.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveToLeft(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointB
			.MoveToLeft(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance)
				->MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointC
			.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveToLeft(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance);

		upperLine
			.MoveUpwards(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(orientation == Degrees270)
	{
		upperConductor
			.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint
			.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToRight(NpnTransistorResources::Radius);

		midLine
			.MoveToLeft(NpnTransistorResources::Height - NpnTransistorResources::Radius)
				->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveDownwards(BaseComponentResources::connectorWidth);

		lowerStartPoint
			.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(NpnTransistorResources::EntriLine);
		upperStartPoint
			.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToRight(NpnTransistorResources::EntriLine);

		pointA
			.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveUpwards(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointB
			.MoveUpwards(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance)
				->MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance - NpnTransistorResources::DistanceFromaPoint);
		pointC
			.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors + NpnTransistorResources::TriangleDistance)
				->MoveUpwards(NpnTransistorResources::DistanceFromaPoint + NpnTransistorResources::TriangleDistance);

		upperLine
			.MoveToRight(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
	}
	GraphicsHelper::DrawCircle(startPoint, NpnTransistorResources::Radius);
	GraphicsHelper::DrawLine(midStartPoint, midLine);
	GraphicsHelper::DrawLine(lineStartPoint, line);
	GraphicsHelper::DrawLine(upperStartPoint, upperConductor);
	GraphicsHelper::DrawLine(lowerStartPoint, lowerConductor);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	GraphicsHelper::DrawLine(upperConductor, upperLine);

	connectorPoints.clear();
	PushConnectorPoint(upperLine);
	PushConnectorPoint(line);
	PushConnectorPoint(pointC);

}
