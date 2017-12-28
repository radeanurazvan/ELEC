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
	if (Orientation == Normal)
	{
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

		const auto topConnectorPoint = topLeftPoint.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);
		const auto bottomConnectorPoint = bottomLeftPoint.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);

		auto middleConnectorPoint = circleCenterPoint->MoveToRight(NandGateResources::circleRadius);
		auto middleConnectorPointLine = *middleConnectorPoint;
		middleConnectorPointLine.MoveToRight(NandGateResources::connectorWidth);
		auto topConnectorPointLine = *topConnectorPoint;
		topConnectorPointLine.MoveToRight(-NandGateResources::connectorWidth);
		auto bottomConnectorPointLine = *bottomConnectorPoint;
		bottomConnectorPointLine.MoveToRight(-NandGateResources::connectorWidth);
		GraphicsHelper::DrawLine(*middleConnectorPoint, middleConnectorPointLine);
		GraphicsHelper::DrawLine(*topConnectorPoint, topConnectorPointLine);
		GraphicsHelper::DrawLine(*bottomConnectorPoint, bottomConnectorPointLine);
	}
	else if(Orientation == Degrees180)
	{
		topLeftPoint.MoveUpwards(NandGateResources::height);

		bottomRightPoint.MoveToLeft(NandGateResources::length);
		topRightPoint
			.MoveToLeft(NandGateResources::length)
			->MoveUpwards(NandGateResources::height);

		GraphicsHelper::DrawLine(bottomLeftPoint, topLeftPoint);
		GraphicsHelper::DrawLine(bottomLeftPoint, bottomRightPoint);
		GraphicsHelper::DrawLine(topLeftPoint, topRightPoint);

		auto arcCenterPoint = CartesianPointsHelper::GetMiddlePointBetween(topRightPoint, bottomRightPoint).MoveUpwards(1);
		GraphicsHelper::DrawArc(*arcCenterPoint,-NandGateResources::arcStartAngle,-NandGateResources::arcEndAngle, NandGateResources::arcRadius);

		auto circleCenterPoint = arcCenterPoint->MoveToLeft(NandGateResources::arcRadius + NandGateResources::circleRadius);
		GraphicsHelper::DrawCircle(*circleCenterPoint, NandGateResources::circleRadius);

		const auto topConnectorPoint = topLeftPoint.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);
		const auto bottomConnectorPoint = bottomLeftPoint.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);

		auto middleConnectorPoint = circleCenterPoint->MoveToLeft(NandGateResources::circleRadius);
		auto middleConnectorPointLine = *middleConnectorPoint;
		middleConnectorPointLine.MoveToLeft(NandGateResources::connectorWidth);
		auto topConnectorPointLine = *topConnectorPoint;
		topConnectorPointLine.MoveToLeft(-NandGateResources::connectorWidth);
		auto bottomConnectorPointLine = *bottomConnectorPoint;
		bottomConnectorPointLine.MoveToLeft(-NandGateResources::connectorWidth);
		GraphicsHelper::DrawLine(*middleConnectorPoint, middleConnectorPointLine);
		GraphicsHelper::DrawLine(*topConnectorPoint, topConnectorPointLine);
		GraphicsHelper::DrawLine(*bottomConnectorPoint, bottomConnectorPointLine);
	}

}
