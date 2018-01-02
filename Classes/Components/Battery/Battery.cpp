#include "Battery.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/BatteryResources.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"


Battery::Battery()
{
	SetName(name);
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

	if(orientation == Degrees90)
	{
		std::swap(rightPointHeightDistance, rightPointSideDistance);
	}

	if(orientation == Degrees270)
	{
		rightPointHeightDistance = BatteryResources::spaceBetweenConductors;
	}

	if(orientation == Degrees90 || orientation == Degrees180)
	{
		rightLineDistance = -rightLineDistance;
		rightPointHeightDistance = -rightPointHeightDistance;
	}

	if (orientation == Degrees180 || orientation == Degrees270)
	{
		rightPointSideDistance = -rightPointSideDistance;
		leftLineDistance = -leftLineDistance;
		leftPointDistance = -leftPointDistance;
	}

	if(orientation == Normal || orientation == Degrees180)
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
	if (orientation == Normal)
	{
		DrawMiddleConnectors(leftConnector, rightConnector);
	}
	else if (orientation == Degrees90)
	{
		DrawMiddleConnectors90Degrees(leftConnector, rightConnector);
	}
	else if (orientation == Degrees180)
	{
		DrawMiddleConnectors(rightConnector, leftConnector);
	}
	else
	{
		DrawMiddleConnectors90Degrees(rightConnector, leftConnector);
	}
}
