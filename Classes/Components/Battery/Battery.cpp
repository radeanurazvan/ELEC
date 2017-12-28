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
	if (Orientation == Normal)
	{
		rightConductorPoint.MoveToRight(BatteryResources::spaceBetweenConductors);
		rightConductorPoint.MoveUpwards(BatteryResources::conductorRightHeight * 1.5);

		auto leftConductorPointLine = leftConductorPoint;
		leftConductorPointLine.MoveUpwards(BatteryResources::conductorLeftHeight);
		GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);

		auto rightConductorPointLine = rightConductorPoint;
		rightConductorPointLine.MoveUpwards (-BatteryResources::conductorRightHeight);
		GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);
		
		auto connectorsDrawReferencePoint = leftConductorPoint;
		connectorsDrawReferencePoint
			.MoveToRight(BatteryResources::spaceBetweenConductors)
			->MoveUpwards(BatteryResources::conductorLeftHeight);

		DrawMiddleConnectors(leftConductorPoint, connectorsDrawReferencePoint);
	}
	else if(Orientation== Degrees90)
	{ }
	else if(Orientation== Degrees180)
	{
		rightConductorPoint.MoveToLeft(BatteryResources::spaceBetweenConductors);
		rightConductorPoint.MoveUpwards(BatteryResources::conductorRightHeight * 1.5);
		

		auto leftConductorPointLine = leftConductorPoint;
		leftConductorPointLine.MoveUpwards(BatteryResources::conductorLeftHeight);
		GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);

		auto rightConductorPointLine = rightConductorPoint;
		rightConductorPointLine.MoveUpwards(-BatteryResources::conductorRightHeight);
		GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);

		auto connectorsDrawReferencePoint = rightConductorPoint;
		connectorsDrawReferencePoint
			.MoveToRight(BatteryResources::spaceBetweenConductors)
			->MoveDownwards(BatteryResources::conductorRightHeight);
		DrawMiddleConnectors(rightConductorPoint, connectorsDrawReferencePoint);


		
	
		
	
		

		
		
	
	}
	else if(Orientation== Degrees270)
	{ }

}
