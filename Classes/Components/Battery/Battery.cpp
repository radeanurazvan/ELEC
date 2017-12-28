#include "Battery.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/BatteryResources.h"


Battery::Battery()
{
}

void Battery::Draw()
{
	auto leftConductorPoint = GetReferencePoint();
	auto rightConductorPoint = GetReferencePoint();

	Battery::ChangeTheMove(CartesianPoint rightConductorPoint);
	rightConductorPoint.MoveUpwards(BatteryResources::conductorRightHeight * 1.5);

	auto leftConductorPointLine = leftConductorPoint;
	leftConductorPointLine.MoveUpwards(BatteryResources::conductorLeftHeight);
	GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);

	auto rightConductorPointLine = rightConductorPoint;
	rightConductorPointLine.MoveUpwards(-BatteryResources::conductorRightHeight);
	GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);
	
	Battery::PrepareReferencePointsForDrawing(rightConductorPoint, leftConductorPoint);
	
}

void Battery::PrepareReferencePointsForDrawing(CartesianPoint rightPoint, CartesianPoint leftPoint)
{
	if (Orientation == Normal)
	{
		auto connectorsDrawReferencePoint = leftConductorPoint;
		connectorsDrawReferencePoint
			.MoveToRight(BatteryResources::spaceBetweenConductors)
			->MoveUpwards(BatteryResources::conductorLeftHeight);

		DrawMiddleConnectors(leftConductorPoint, connectorsDrawReferencePoint);
		
	}
	else if (Orientation == Degrees180)
	{
		auto connectorsDrawReferencePoint = rightConductorPoint;
		connectorsDrawReferencePoint
			.MoveToRight(BatteryResources::spaceBetweenConductors)
			->MoveDownwards(BatteryResources::conductorRightHeight);
		DrawMiddleConnectors(rightConductorPoint, connectorsDrawReferencePoint);
		
	}
}
void Battery::ChangeTheMove(CartesianPoint rightConductorPoint)
{if(Orientation==Normal)
{rightConductorPoint.MoveToRight(BatteryResources::spaceBetweenConductors);}
else
{rightConductorPoint.MoveToLeft(BatteryResources::spaceBetweenConductors); }

}