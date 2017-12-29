 #include "Battery.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/BatteryResources.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"


Battery::Battery()
{
}

void Battery::Draw()
{
	auto leftConductorPoint = GetReferencePoint();
	auto rightConductorPoint = GetReferencePoint();
	auto leftConductorPointLine = leftConductorPoint;
	auto rightConductorPointLine = rightConductorPoint;
if(Orientation == Normal)
{
	rightConductorPoint
		.MoveUpwards(BatteryResources::conductorRightHeight)
			->MoveToRight(BatteryResources::spaceBetweenConductors);
	rightConductorPointLine.MoveToRight(BatteryResources::spaceBetweenConductors);

	leftConductorPointLine.MoveUpwards(BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight / 2);
	leftConductorPoint.MoveDownwards((BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight) / 2);
}
else
if(Orientation == Degrees90)
{
	rightConductorPoint
		.MoveToRight(BatteryResources::conductorRightHeight)
		->MoveDownwards(BatteryResources::spaceBetweenConductors);
	rightConductorPointLine.MoveDownwards(BatteryResources::spaceBetweenConductors);

	leftConductorPointLine.MoveToRight(BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight / 2);
	leftConductorPoint.MoveToLeft((BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight) / 2);
}
else
if(Orientation == Degrees180)
{
	rightConductorPoint
		.MoveDownwards(BatteryResources::conductorRightHeight)
		->MoveToLeft(BatteryResources::spaceBetweenConductors);
	rightConductorPointLine.MoveToLeft(BatteryResources::spaceBetweenConductors);

	leftConductorPointLine.MoveDownwards(BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight / 2);
	leftConductorPoint.MoveUpwards((BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight) / 2);
}
else
if(Orientation == Degrees270)
{
	rightConductorPoint
		.MoveToLeft(BatteryResources::conductorRightHeight)
		->MoveUpwards(BatteryResources::spaceBetweenConductors);
	rightConductorPointLine.MoveUpwards(BatteryResources::spaceBetweenConductors);

	leftConductorPointLine.MoveToLeft(BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight / 2);
	leftConductorPoint.MoveToRight((BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight) / 2);
}
	auto leftConnector = CartesianPointsHelper::GetMiddlePointBetween(leftConductorPoint, leftConductorPointLine);
	auto rightConnector = CartesianPointsHelper::GetMiddlePointBetween(rightConductorPoint, rightConductorPointLine);
	GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);
	GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);
	if (Orientation == Normal)
		DrawMiddleConnectors(leftConnector, rightConnector);
	else
	if(Orientation == Degrees90)
		DrawMiddleConnectors90Degrees(leftConnector, rightConnector);
	else
	if(Orientation == Degrees180)
		DrawMiddleConnectors(rightConnector, leftConnector);
	else
		DrawMiddleConnectors90Degrees(rightConnector, leftConnector);
}


