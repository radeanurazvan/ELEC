#include "NandGate.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/NandGateResources.h"
#include "../BaseComponent/Resources/BaseComponentResources.h"


CartesianPoint NandGate::GetReferencePoint()
{
	auto referencePoint = BaseComponent::GetReferencePoint();

	referencePoint.MoveToRight(BaseComponentResources::connectorWidth);
	if(orientation != Degrees270)
	{
		referencePoint.MoveUpwards(BaseComponentResources::connectorWidth);
	}
	return referencePoint;
}

NandGate::NandGate()
	: BaseComponent(NandGateResources::ActualContainerSize)
{
	SetName(name);
}

void NandGate::Draw()
{
	auto topLeftPoint = GetReferencePoint();
	auto bottomLeftPoint = topLeftPoint;
	auto leftUpperLine = topLeftPoint;
	auto leftLowerLine = topLeftPoint;
	auto topConnectorStart = topLeftPoint;
	auto topConnectorEnd = topLeftPoint;
	auto middleConnectorStart = topLeftPoint;
	auto middleConnectorEnd = topLeftPoint;
	auto bottomConnectorStart = topLeftPoint;
	auto bottomConnectorEnd = topLeftPoint;
	auto circleCenterPoint = topLeftPoint;

	if (orientation == Normal)
	{
		topLeftPoint.MoveUpwards(NandGateResources::height);
		leftUpperLine.Copy(topLeftPoint)->MoveToRight(NandGateResources::length);
		leftLowerLine.MoveToRight(NandGateResources::length);

		auto arcCenterPoint = CartesianPointsHelper::GetMiddlePointBetween(leftUpperLine, leftLowerLine);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle0, NandGateResources::arcEndAngle0, NandGateResources::arcRadius);
		
		circleCenterPoint.Copy(arcCenterPoint)->MoveToRight(NandGateResources::arcRadius + NandGateResources::circleRadius);

		middleConnectorStart.Copy(circleCenterPoint)->MoveToRight(NandGateResources::circleRadius);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveToRight(BaseComponentResources::connectorWidth);

		topConnectorStart.Copy(topLeftPoint)->MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveToLeft(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomLeftPoint)->MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveToLeft(BaseComponentResources::connectorWidth);

	}
	else
	if(orientation == Degrees90)
	{
		bottomLeftPoint.MoveUpwards(2 * NandGateResources::circleRadius + NandGateResources::arcRadius + NandGateResources::length);
		topLeftPoint.Copy(bottomLeftPoint)->MoveToRight(NandGateResources::height);
		leftUpperLine.Copy(topLeftPoint)->MoveDownwards(NandGateResources::length);
		leftLowerLine.Copy(bottomLeftPoint)->MoveDownwards(NandGateResources::length);

		topConnectorStart.Copy(topLeftPoint)->MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveUpwards(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomLeftPoint)->MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveUpwards(BaseComponentResources::connectorWidth);

		auto arcCenterPoint = CartesianPointsHelper::GetMiddlePointBetween(leftUpperLine, leftLowerLine);
		circleCenterPoint.Copy(arcCenterPoint)->MoveDownwards(NandGateResources::arcRadius + NandGateResources::circleRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle90, NandGateResources::arcEndAngle90, NandGateResources::arcRadius);

		middleConnectorStart.Copy(circleCenterPoint)->MoveDownwards(NandGateResources::circleRadius);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveDownwards(BaseComponentResources::connectorWidth);

	}
	if(orientation == Degrees180)
	{
		bottomLeftPoint.MoveToRight(2 * NandGateResources::circleRadius + NandGateResources::arcRadius + NandGateResources::length);
		topLeftPoint.Copy(bottomLeftPoint)->MoveUpwards(NandGateResources::height);

		leftUpperLine.Copy(topLeftPoint)->MoveToLeft(NandGateResources::length);
		leftLowerLine.Copy(bottomLeftPoint)->MoveToLeft(NandGateResources::length);

		auto arcCenterPoint = CartesianPointsHelper::GetMiddlePointBetween(leftUpperLine, leftLowerLine);
		circleCenterPoint.Copy(arcCenterPoint)->MoveToLeft(NandGateResources::arcRadius + NandGateResources::circleRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle180, NandGateResources::arcEndAngle180, NandGateResources::arcRadius);

		topConnectorStart.Copy(topLeftPoint)->MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveToRight(BaseComponentResources::connectorWidth);
		bottomConnectorStart.Copy(bottomLeftPoint)->MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveToRight(BaseComponentResources::connectorWidth);

		middleConnectorStart.Copy(circleCenterPoint)->MoveToLeft(NandGateResources::circleRadius);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveToLeft(BaseComponentResources::connectorWidth);
	}
	else
	if(orientation == Degrees270)
	{
		bottomLeftPoint.MoveUpwards(BaseComponentResources::connectorWidth);
		topLeftPoint.Copy(bottomLeftPoint)->MoveToRight(NandGateResources::height);
		
		leftUpperLine.Copy(topLeftPoint)->MoveUpwards(NandGateResources::length);
		leftLowerLine.Copy(bottomLeftPoint)->MoveUpwards(NandGateResources::length);

		auto arcCenterPoint = CartesianPointsHelper::GetMiddlePointBetween(leftUpperLine, leftLowerLine);
		circleCenterPoint.Copy(arcCenterPoint)->MoveUpwards(NandGateResources::arcRadius + NandGateResources::circleRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle270, NandGateResources::arcEndAngle270, NandGateResources::arcRadius);

		topConnectorStart.Copy(topLeftPoint)->MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveDownwards(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomLeftPoint)->MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveDownwards(BaseComponentResources::connectorWidth);

		middleConnectorStart.Copy(circleCenterPoint)->MoveUpwards(NandGateResources::circleRadius);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveUpwards(BaseComponentResources::connectorWidth);
	}
	GraphicsHelper::DrawLine(bottomLeftPoint, leftLowerLine);
	GraphicsHelper::DrawLine(topLeftPoint, leftUpperLine);
	GraphicsHelper::DrawLine(bottomLeftPoint, topLeftPoint);
	GraphicsHelper::DrawLine(topConnectorStart, topConnectorEnd);
	GraphicsHelper::DrawLine(middleConnectorStart, middleConnectorEnd);
	GraphicsHelper::DrawLine(bottomConnectorStart, bottomConnectorEnd);
	GraphicsHelper::DrawCircle(circleCenterPoint, NandGateResources::circleRadius);

	connectorPoints.clear();
	PushConnectorPoint(leftLowerLine);
	PushConnectorPoint(middleConnectorEnd);
	PushConnectorPoint(bottomConnectorEnd);

}
