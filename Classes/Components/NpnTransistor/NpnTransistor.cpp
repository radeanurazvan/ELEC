#include "NpnTransistor.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NpnTransistorResources.h"

NpnTransistor::NpnTransistor()
{
	
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
	
	
	if (Orientation == Normal)
	{
		upperConductor.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveDownwards(NpnTransistorResources::Radius);

		midLine.MoveUpwards(NpnTransistorResources::Height - NpnTransistorResources::Radius);
		midLine.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveToLeft(NpnTransistorResources::Lenght );

		lowerStartPoint.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveUpwards(NpnTransistorResources::EntriLine);
		upperStartPoint.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveDownwards(NpnTransistorResources::EntriLine);

		pointA.MoveDownwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveToLeft(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint );
		pointB.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		upperLine.MoveDownwards(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors);
		upperLine.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees90)
	{	
		upperConductor.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveToLeft(NpnTransistorResources::Radius);

		midLine.MoveToRight(NpnTransistorResources::Height - NpnTransistorResources::Radius);
		midLine.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveUpwards(NpnTransistorResources::Lenght);

		lowerStartPoint.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveToRight(NpnTransistorResources::EntriLine);
		upperStartPoint.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveToLeft(NpnTransistorResources::EntriLine);

		pointA.MoveToLeft(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveUpwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		upperLine.MoveToLeft(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors);
		upperLine.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees180)
	{
		upperConductor.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveUpwards(NpnTransistorResources::Radius);

		midLine.MoveDownwards(NpnTransistorResources::Height - NpnTransistorResources::Radius);
		midLine.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveToRight(NpnTransistorResources::Lenght);

		lowerStartPoint.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveDownwards(NpnTransistorResources::EntriLine);
		upperStartPoint.MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveUpwards(NpnTransistorResources::EntriLine);

		pointA.MoveUpwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveToRight(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		upperLine.MoveUpwards(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors);
		upperLine.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees270)
	{
		upperConductor.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors);
		upperConductor.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		lowerConductor.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors);
		lowerConductor.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		midConductor.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		midStartPoint.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		midStartPoint.MoveToRight(NpnTransistorResources::Radius);

		midLine.MoveToLeft(NpnTransistorResources::Height - NpnTransistorResources::Radius);
		midLine.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveDownwards(NpnTransistorResources::Lenght);

		lowerStartPoint.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		lowerStartPoint.MoveToLeft(NpnTransistorResources::EntriLine);
		upperStartPoint.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		upperStartPoint.MoveToRight(NpnTransistorResources::EntriLine);

		pointA.MoveToRight(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors);
		pointA.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveDownwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint);
		pointB.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

		upperLine.MoveToRight(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors);
		upperLine.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
	}
	GraphicsHelper::DrawCircle(startPoint, NpnTransistorResources::Radius);
	GraphicsHelper::DrawLine(midStartPoint, midLine);
	GraphicsHelper::DrawLine(lineStartPoint, line);
	GraphicsHelper::DrawLine(upperStartPoint, upperConductor);
	GraphicsHelper::DrawLine(lowerStartPoint, lowerConductor);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	GraphicsHelper::DrawLine(upperConductor, upperLine);
}
