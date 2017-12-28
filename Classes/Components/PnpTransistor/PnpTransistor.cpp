#include "PnpTransistor.h"
#include "../../Classes/Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/PnpTransistorResources.h"

PnpTransistor::PnpTransistor()
{
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
	
	if (Orientation == Normal)
	{
		upperConductor.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		midLine.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
		midLine.MoveUpwards(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveDownwards(PnpTransistorResources::Radius);

		lowerStartPoint.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveUpwards(PnpTransistorResources::EntriLine);
		upperStartPoint.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveDownwards(PnpTransistorResources::EntriLine);
		
		Line.MoveToLeft(PnpTransistorResources::Lenght);

		pointC.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointC.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointA.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors- PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint- PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		lowerLine.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees90)
	{
		upperConductor.MoveToLeft(PnpTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveToRight(PnpTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);

		midLine.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
		midLine.MoveToRight(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveToLeft(PnpTransistorResources::Radius);

		lowerStartPoint.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveToRight(PnpTransistorResources::EntriLine);
		upperStartPoint.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveToLeft(PnpTransistorResources::EntriLine);

		Line.MoveUpwards(PnpTransistorResources::Lenght);

		pointC.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointC.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointA.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		lowerLine.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees180)
	{
		upperConductor.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		midLine.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
		midLine.MoveDownwards(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveUpwards(PnpTransistorResources::Radius);

		lowerStartPoint.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveDownwards(PnpTransistorResources::EntriLine);
		upperStartPoint.MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveUpwards(PnpTransistorResources::EntriLine);

		Line.MoveToRight(PnpTransistorResources::Lenght);

		pointC.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointC.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointA.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		lowerLine.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees270)
	{
		upperConductor.MoveToRight(PnpTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveToLeft(PnpTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);

		midLine.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
		midLine.MoveToLeft(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveToRight(PnpTransistorResources::Radius);

		lowerStartPoint.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveToLeft(PnpTransistorResources::EntriLine);
		upperStartPoint.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveToRight(PnpTransistorResources::EntriLine);

		Line.MoveDownwards(PnpTransistorResources::Lenght);

		pointC.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointC.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint);
		pointA.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint);
		pointB.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		lowerLine.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
	}
	GraphicsHelper::DrawCircle(startPoint, PnpTransistorResources::Radius);
	GraphicsHelper::DrawLine(midStartPoint, midLine);
	GraphicsHelper::DrawLine(midConductor, Line);
	GraphicsHelper::DrawLine(upperStartPoint, upperConductor);
	GraphicsHelper::DrawLine(lowerStartPoint, lowerConductor);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	GraphicsHelper::DrawLine(lowerConductor, lowerLine);
		
	
}
