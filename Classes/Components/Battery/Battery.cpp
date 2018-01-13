#include "Battery.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/BatteryResources.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"


Battery::Battery()
	: BaseComponent(BatteryResources::actualContainerSize)
{
	SetName(name);
}

void Battery::Draw()
{
	auto leftConductorBottomPoint = GetReferencePoint();
	auto rightConductorBottomPoint = leftConductorBottomPoint;
	auto leftConductorTopPoint = leftConductorBottomPoint;
	auto rightConductorTopPoint = leftConductorBottomPoint;

	PrepareConnectorPointsForDrawing(leftConductorBottomPoint, leftConductorTopPoint, rightConductorBottomPoint, rightConductorTopPoint);

	const auto leftConnector = CartesianPointsHelper::GetMiddlePointBetween(leftConductorBottomPoint, leftConductorTopPoint);
	const auto rightConnector = CartesianPointsHelper::GetMiddlePointBetween(rightConductorBottomPoint, rightConductorTopPoint);
	GraphicsHelper::DrawLine(leftConductorBottomPoint, leftConductorTopPoint);
	GraphicsHelper::DrawLine(rightConductorBottomPoint, rightConductorTopPoint);
	DrawConnectors(leftConnector, rightConnector);
}

void Battery::PrepareConnectorPointsForDrawing(CartesianPoint& leftConductorBottomPoint,
	CartesianPoint& leftConductorTopPoint, CartesianPoint& rightConductorBottomPoint, CartesianPoint& rightConductorTopPoint)
{
	InitLeftConnectorBottomPoint(leftConductorBottomPoint);
	const auto rightConductorPadding = (BatteryResources::leftConductorHeight - BatteryResources::rightConductorHeight) / 2;
	auto rightConductorBottomPointSideDistance = BatteryResources::spaceBetweenConductors;
	auto rightConductorBottomPointHeightDistance = rightConductorPadding;

	rightConductorBottomPoint = leftConductorBottomPoint;
	leftConductorTopPoint = leftConductorBottomPoint;
	rightConductorTopPoint = leftConductorBottomPoint;

	if(orientation == Degrees180)
	{
		rightConductorBottomPointSideDistance = -rightConductorBottomPointSideDistance;
	}
	if(orientation == Degrees90)
	{
		rightConductorBottomPointHeightDistance = -rightConductorBottomPointHeightDistance;
	}

	rightConductorBottomPoint
		.MoveToSide(rightConductorBottomPointSideDistance)
		->MoveInHeight(rightConductorBottomPointHeightDistance);
	rightConductorTopPoint.Copy(rightConductorBottomPoint);

	if (orientation == Normal || orientation == Degrees180)
	{
		leftConductorTopPoint.MoveUpwards(BatteryResources::leftConductorHeight);
		rightConductorTopPoint.MoveUpwards(BatteryResources::rightConductorHeight);
	}
	else
	{
		leftConductorTopPoint.MoveToRight(BatteryResources::leftConductorHeight);
		rightConductorTopPoint.MoveToRight(BatteryResources::rightConductorHeight);
	}
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

void Battery::InitLeftConnectorBottomPoint(CartesianPoint& leftConnectorBottomPoint)
{
	auto leftConductorBottomPointDistance = BaseComponentResources::connectorWidth;

	if (orientation == Degrees90 || orientation == Degrees180)
	{
		leftConductorBottomPointDistance += BatteryResources::spaceBetweenConductors;
	}

	if (orientation == Normal || orientation == Degrees180)
	{
		leftConnectorBottomPoint.MoveToRight(leftConductorBottomPointDistance);
	}

	if (orientation == Degrees90 || orientation == Degrees270)
	{
		leftConnectorBottomPoint.MoveUpwards(leftConductorBottomPointDistance);
	}
}
