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
	if (Orientation == Normal)
	{
		rightConductorPoint.MoveToRight(BatteryResources::spaceBetweenConductors);
		rightConductorPoint.MoveUpwards(BatteryResources::conductorRightHeight * 1.5);


		GraphicsHelper::DrawLine(leftConductorPoint, BatteryResources::conductorLeftHeight);
		GraphicsHelper::DrawLine(rightConductorPoint, -BatteryResources::conductorRightHeight);

		auto connectorsDrawReferencePoint = leftConductorPoint;
		connectorsDrawReferencePoint
			.MoveToRight(BatteryResources::spaceBetweenConductors)
			->MoveUpwards(BatteryResources::conductorLeftHeight);

		DrawMiddleConnectors(leftConductorPoint, connectorsDrawReferencePoint);
	}
	else if(Orientation== Degrees90)
	{ }
	else if(Orientation== Degrees180)
	{}
	else if(Orientation== Degrees270)
	{ }

}
