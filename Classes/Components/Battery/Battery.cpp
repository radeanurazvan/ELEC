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

	PrepareConnectorPointsForDrawing(leftConductorPoint, leftConductorPointLine, rightConductorPoint, rightConductorPointLine);

	auto leftConnector = CartesianPointsHelper::GetMiddlePointBetween(leftConductorPoint, leftConductorPointLine);
	auto rightConnector = CartesianPointsHelper::GetMiddlePointBetween(rightConductorPoint, rightConductorPointLine);
	GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);
	GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);
	DrawConnectors(leftConnector, rightConnector);
}

void Battery::PrepareConnectorPointsForDrawing(CartesianPoint& leftConductorPoint,
	CartesianPoint& leftConductorPointLine, CartesianPoint& rightConductorPoint, CartesianPoint& rightConductorPointLine)
{
	auto rightPointHeightDistance = BatteryResources::conductorRightHeight;
	auto rightPointSideDistance = BatteryResources::spaceBetweenConductors;
	auto rightLineDistance = BatteryResources::spaceBetweenConductors;
	auto leftLineDistance = BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight / 2;
	auto leftPointDistance = -((BatteryResources::conductorLeftHeight - BatteryResources::conductorRightHeight) / 2);

	if(Orientation == Degrees90)
	{
		std::swap(rightPointHeightDistance, rightPointSideDistance);
	}

	if(Orientation == Degrees270)
	{
		rightPointHeightDistance = BatteryResources::spaceBetweenConductors;
	}

	if(Orientation == Degrees90 || Orientation == Degrees180)
	{
		rightLineDistance = -rightLineDistance;
		rightPointHeightDistance = -rightPointHeightDistance;
	}

	if (Orientation == Degrees180 || Orientation == Degrees270)
	{
		rightPointSideDistance = -rightPointSideDistance;
		leftLineDistance = -leftLineDistance;
		leftPointDistance = -leftPointDistance;
	}

	if(Orientation == Normal || Orientation == Degrees180)
	{
		rightConductorPointLine.MoveToSide(rightLineDistance);
		leftConductorPointLine.MoveInHeight(leftLineDistance);
		leftConductorPoint.MoveInHeight(leftPointDistance);
	} else
	{
		rightConductorPointLine.MoveInHeight(rightLineDistance);
		leftConductorPointLine.MoveToSide(leftLineDistance);
		leftConductorPoint.MoveToSide(leftPointDistance);
	}

	rightConductorPoint
		.MoveToSide(rightPointSideDistance)
		->MoveInHeight(rightPointHeightDistance);
}

void Battery::DrawConnectors(CartesianPoint leftConnector, CartesianPoint rightConnector)
{
	if (Orientation == Normal)
	{
		DrawMiddleConnectors(leftConnector, rightConnector);
	}
	else if (Orientation == Degrees90)
	{
		DrawMiddleConnectors90Degrees(leftConnector, rightConnector);
	}
	else if (Orientation == Degrees180)
	{
		DrawMiddleConnectors(rightConnector, leftConnector);
	}
	else
	{
		DrawMiddleConnectors90Degrees(rightConnector, leftConnector);
	}
}
