#include "Battery.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/BatteryResources.h"


Battery::Battery()
{
}

void Battery::Draw()
{
	const auto leftConductorPoint = GetReferencePoint();
	auto rightConductorPoint = GetReferencePoint();
	rightConductorPoint.MoveToRight(BatteryResources::spaceBetweenConductors);
	rightConductorPoint.MoveUpwards(BatteryResources::conductorRightHeight * 1.5);
	

	GraphicsHelper::DrawSegmnentOfHeight(leftConductorPoint, BatteryResources::conductorLeftHeight);
	GraphicsHelper::DrawSegmnentOfHeight(rightConductorPoint, -BatteryResources::conductorRightHeight);

	DrawMiddleConnectors(leftConductorPoint, rightConductorPoint);

}
