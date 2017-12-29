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
		upperConductor
			.MoveDownwards(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		lowerConductor
			.MoveUpwards(PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(PnpTransistorResources::DistanceFromMidPoint);

		midConductor.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);

		midLine
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::Height - PnpTransistorResources::Radius);

		midStartPoint
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::Radius);

		lowerStartPoint
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::EntriLine);
		
		upperStartPoint
			.MoveToLeft(PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::EntriLine);
		
		Line.MoveToLeft(PnpTransistorResources::Lenght);

		pointC
			.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors- PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint- PnpTransistorResources::DistanceFromaPoint)
				->MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToRight(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees90)
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
				->MoveToRight(PnpTransistorResources::EntriLine);
		upperStartPoint
			.MoveUpwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::EntriLine);

		Line.MoveUpwards(PnpTransistorResources::Lenght);

		pointC
			.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint)
				->MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveDownwards(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees180)
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
				->MoveDownwards(PnpTransistorResources::EntriLine);
		upperStartPoint
			.MoveToRight(PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::EntriLine);

		Line.MoveToRight(PnpTransistorResources::Lenght);

		pointC
			.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint)
				->MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveDownwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveToLeft(PnpTransistorResources::DistanceFromMidPoint);
	}
	else
	if(Orientation == Degrees270)
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
				->MoveToLeft(PnpTransistorResources::EntriLine);
		upperStartPoint
			.MoveDownwards(PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::EntriLine);

		Line.MoveDownwards(PnpTransistorResources::Lenght);

		pointC
			.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);
		pointA
			.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint)
				->MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors - PnpTransistorResources::DistanceFromaPoint);
		pointB
			.MoveUpwards(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceFromMidPoint - PnpTransistorResources::DistanceFromaPoint)
				->MoveToRight(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors);

		lowerLine
			.MoveToLeft(PnpTransistorResources::EntriLine + PnpTransistorResources::DistanceBetweenCondcutors)
				->MoveUpwards(PnpTransistorResources::DistanceFromMidPoint);
	}
	GraphicsHelper::DrawCircle(startPoint, PnpTransistorResources::Radius);
	GraphicsHelper::DrawLine(midStartPoint, midLine);
	GraphicsHelper::DrawLine(midConductor, Line);
	GraphicsHelper::DrawLine(upperStartPoint, upperConductor);
	GraphicsHelper::DrawLine(lowerStartPoint, lowerConductor);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	GraphicsHelper::DrawLine(lowerConductor, lowerLine);
}
