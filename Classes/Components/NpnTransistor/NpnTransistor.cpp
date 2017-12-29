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
			.MoveUpwards(NpnTransistorResources::Height - NpnTransistorResources::Radius)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		line.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		lineStartPoint.MoveToLeft(NpnTransistorResources::Lenght );

		lowerStartPoint
			.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(NpnTransistorResources::EntriLine);
		upperStartPoint
			.MoveToLeft(NpnTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(NpnTransistorResources::EntriLine);

		pointA
			.MoveDownwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
		pointB
			.MoveToLeft(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint )
				->MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC
			.MoveUpwards(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);

		upperLine
			.MoveDownwards(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees90)
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
		lineStartPoint.MoveUpwards(NpnTransistorResources::Lenght);

		lowerStartPoint
			.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToRight(NpnTransistorResources::EntriLine);

		upperStartPoint
			.MoveUpwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(NpnTransistorResources::EntriLine);

		pointA
			.MoveToLeft(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors)
					->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
		pointB
			.MoveUpwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint)
				->MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC
			.MoveToRight(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);

		upperLine
			.MoveToLeft(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees180)
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
		lineStartPoint.MoveToRight(NpnTransistorResources::Lenght);

		lowerStartPoint
			.MoveToRight(NpnTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(NpnTransistorResources::EntriLine);
		upperStartPoint
			.MoveToRight(NpnTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(NpnTransistorResources::EntriLine);

		pointA
			.MoveUpwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
		pointB
			.MoveToRight(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC
			.MoveDownwards(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);

		upperLine
			.MoveUpwards(NpnTransistorResources::EntriLine + NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(NpnTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees270)
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
		lineStartPoint.MoveDownwards(NpnTransistorResources::Lenght);

		lowerStartPoint
			.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(NpnTransistorResources::EntriLine);
		upperStartPoint
			.MoveDownwards(NpnTransistorResources::DistanceFromMidPoint)
				->MoveToRight(NpnTransistorResources::EntriLine);

		pointA
			.MoveToRight(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);
		pointB
			.MoveDownwards(NpnTransistorResources::DistanceFromaPoint - NpnTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors);
		pointC
			.MoveToLeft(NpnTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(NpnTransistorResources::DistanceFromMidPoint);

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
}
