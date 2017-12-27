#include "NandGate.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/NandGateResources.h"


NandGate::NandGate()
{
}

void NandGate::Draw()
{
	CartesianPoint bottomLeftPoint, bottomRightPoint, topLeftPoint, topRightPoint;
	bottomLeftPoint = bottomRightPoint = topLeftPoint = topRightPoint = GetReferencePoint();

	topLeftPoint.MoveUpwards(NandGateResources::height);

	bottomRightPoint.MoveToRight(NandGateResources::length);
	topRightPoint
		.MoveToRight(NandGateResources::length)
		->MoveUpwards(NandGateResources::height);

	GraphicsHelper::DrawLine(bottomLeftPoint, topLeftPoint);
	GraphicsHelper::DrawLine(bottomLeftPoint, bottomRightPoint);
	GraphicsHelper::DrawLine(topLeftPoint, topRightPoint);

	auto arcCenterPoint = CartesianPointsHelper::GetMiddlePointBetween(topRightPoint, bottomRightPoint).MoveUpwards(1);
	GraphicsHelper::DrawArc(*arcCenterPoint, NandGateResources::arcStartAngle, NandGateResources::arcEndAngle, NandGateResources::arcRadius);

	auto circleCenterPoint = arcCenterPoint->MoveToRight(NandGateResources::arcRadius + NandGateResources::circleRadius);
	GraphicsHelper::DrawCircle(*circleCenterPoint, NandGateResources::circleRadius);

	const auto topConnnectorPoint = topLeftPoint.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);
	const auto bottomConnectorPoint = bottomLeftPoint.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);

	auto middleConnectorPoint = circleCenterPoint->MoveToRight(NandGateResources::circleRadius);
	GraphicsHelper::DrawLine(*middleConnectorPoint, NandGateResources::connectorWidth);

	GraphicsHelper::DrawLine(*topConnnectorPoint, -NandGateResources::connectorWidth);
	GraphicsHelper::DrawLine(*bottomConnectorPoint, -NandGateResources::connectorWidth);


}
