#include "NandGate.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/CartesianPointsHelper/CartesianPointsHelper.h"
#include "Resources/NandGateResources.h"
#include "../BaseComponent/Resources/BaseComponentResources.h"


NandGate::NandGate()
	: BaseComponent(NandGateResources::ActualContainerSize)
{
	SetName(name);
}

void NandGate::Draw()
{
	auto bottomLeftPoint = GetReferencePoint();
	auto upperLeftPoint = GetReferencePoint();
	auto topLeftPoint = GetReferencePoint(); 
	auto topRightPoint = GetReferencePoint();
	auto arcCenterPoint = GetReferencePoint();
	auto circleCenterPoint = GetReferencePoint();
	auto middleConnectorPoint = GetReferencePoint();
	auto middleConnectorPointLine = GetReferencePoint();
	auto topConnectorPointLine = GetReferencePoint();
	auto bottomConnectorPointLine = GetReferencePoint();
	auto leftLowerLine = GetReferencePoint();
	auto leftUpperLine = GetReferencePoint();
	auto bottomLine = GetReferencePoint();
	auto topLine = GetReferencePoint();

	if (orientation == Normal)
	{
		arcCenterPoint = *CartesianPointsHelper::GetMiddlePointBetween(topRightPoint, upperLeftPoint).MoveUpwards(1);
		arcCenterPoint.MoveToRight(NandGateResources::arcRadius + NandGateResources::circleRadius);

		////bottomLeftPoint.MoveToRight(2);
		upperLeftPoint
			////.MoveToRight(2)
				.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner );

		leftLowerLine
			.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveToLeft(BaseComponentResources::connectorWidth);
		leftUpperLine
			.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveToLeft(BaseComponentResources::connectorWidth );

		topLeftPoint.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomLeftPoint.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);

		circleCenterPoint = arcCenterPoint;
		circleCenterPoint.MoveToRight(NandGateResources::circleRadius + NandGateResources::arcRadius);
		
		middleConnectorPoint = circleCenterPoint;
		middleConnectorPoint.MoveToRight(NandGateResources::circleRadius);
		middleConnectorPointLine = middleConnectorPoint;
		middleConnectorPointLine.MoveToRight(BaseComponentResources::connectorWidth);

		topConnectorPointLine = arcCenterPoint;
		topConnectorPointLine
			.MoveToLeft(NandGateResources::arcRadius)
				->MoveDownwards(NandGateResources::arcRadius);
		topLine = arcCenterPoint;
		topLine.MoveDownwards(NandGateResources::arcRadius);

		bottomConnectorPointLine = arcCenterPoint;
		bottomConnectorPointLine
			.MoveToLeft(NandGateResources::arcRadius)
				->MoveUpwards(NandGateResources::arcRadius);

		bottomLine = arcCenterPoint;
		bottomLine.MoveUpwards(NandGateResources::arcRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle0, NandGateResources::arcEndAngle0, NandGateResources::arcRadius);
	}
	else
	if(orientation == Degrees90)
	{
		arcCenterPoint = *CartesianPointsHelper::GetMiddlePointBetween(topRightPoint, upperLeftPoint)
			.MoveToRight(1)
				->MoveDownwards(NandGateResources::arcRadius + NandGateResources::circleRadius);

		////bottomLeftPoint.MoveDownwards(2);
		upperLeftPoint
		////.MoveDownwards(2)
		.MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner);

		leftLowerLine
			.MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveUpwards(BaseComponentResources::connectorWidth);
		leftUpperLine
			.MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveUpwards(BaseComponentResources::connectorWidth);

		topLeftPoint.MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomLeftPoint.MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner);

		circleCenterPoint = arcCenterPoint;
		circleCenterPoint.MoveDownwards(NandGateResources::circleRadius + NandGateResources::arcRadius);

		middleConnectorPoint = circleCenterPoint;
		middleConnectorPoint.MoveDownwards(NandGateResources::circleRadius);
		middleConnectorPointLine = middleConnectorPoint;
		middleConnectorPointLine.MoveDownwards(BaseComponentResources::connectorWidth);

		topConnectorPointLine = arcCenterPoint;
		topConnectorPointLine
			.MoveUpwards(NandGateResources::arcRadius)
				->MoveToLeft(NandGateResources::arcRadius);
		topLine = arcCenterPoint;
		topLine.MoveToLeft(NandGateResources::arcRadius);

		bottomConnectorPointLine = arcCenterPoint;
		bottomConnectorPointLine
			.MoveUpwards(NandGateResources::arcRadius)
				->MoveToRight(NandGateResources::arcRadius);
		bottomLine = arcCenterPoint;
		bottomLine.MoveToRight(NandGateResources::arcRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle90, NandGateResources::arcEndAngle90, NandGateResources::arcRadius);
	}
	if(orientation == Degrees180)
	{
		arcCenterPoint = *CartesianPointsHelper::GetMiddlePointBetween(topRightPoint, upperLeftPoint)
			.MoveDownwards(1)
				->MoveToLeft(NandGateResources::arcRadius + NandGateResources::circleRadius);

		////bottomLeftPoint.MoveToLeft(2);
		upperLeftPoint
			////.MoveToLeft(2)
				.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);

		leftLowerLine
			.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveToRight(BaseComponentResources::connectorWidth);
		leftUpperLine
			.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveToRight(BaseComponentResources::connectorWidth);

		topLeftPoint.MoveUpwards(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomLeftPoint.MoveDownwards(NandGateResources::distanceBetweenConnectorAndCorner);

		circleCenterPoint = arcCenterPoint;
		circleCenterPoint.MoveToLeft(NandGateResources::circleRadius + NandGateResources::arcRadius);

		middleConnectorPoint = circleCenterPoint;
		middleConnectorPoint.MoveToLeft(NandGateResources::circleRadius);
		middleConnectorPointLine = middleConnectorPoint;
		middleConnectorPointLine.MoveToLeft(BaseComponentResources::connectorWidth);

		topConnectorPointLine = arcCenterPoint;
		topConnectorPointLine
			.MoveToRight(NandGateResources::arcRadius)
				->MoveUpwards(NandGateResources::arcRadius);
		topLine = arcCenterPoint;
		topLine.MoveUpwards(NandGateResources::arcRadius);

		bottomConnectorPointLine = arcCenterPoint;
		bottomConnectorPointLine
			.MoveToRight(NandGateResources::arcRadius)
				->MoveDownwards(NandGateResources::arcRadius);
		bottomLine = arcCenterPoint;
		bottomLine.MoveDownwards(NandGateResources::arcRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle180, NandGateResources::arcEndAngle180, NandGateResources::arcRadius);
	}
	else
	if(orientation == Degrees270)
	{
		arcCenterPoint = *CartesianPointsHelper::GetMiddlePointBetween(topRightPoint, upperLeftPoint)
			////.MoveToLeft(1)
				.MoveUpwards(NandGateResources::arcRadius + NandGateResources::circleRadius);

		bottomLeftPoint.MoveUpwards(2);
		upperLeftPoint
			////.MoveUpwards(2)
				.MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner);

		leftLowerLine
			.MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveDownwards(BaseComponentResources::connectorWidth);
		leftUpperLine
			.MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner)
				->MoveDownwards(BaseComponentResources::connectorWidth);

		topLeftPoint.MoveToRight(NandGateResources::distanceBetweenConnectorAndCorner);
		bottomLeftPoint.MoveToLeft(NandGateResources::distanceBetweenConnectorAndCorner);

		circleCenterPoint = arcCenterPoint;
		circleCenterPoint.MoveUpwards(NandGateResources::circleRadius + NandGateResources::arcRadius);

		middleConnectorPoint = circleCenterPoint;
		middleConnectorPoint.MoveUpwards(NandGateResources::circleRadius);
		middleConnectorPointLine = middleConnectorPoint;
		middleConnectorPointLine.MoveUpwards(BaseComponentResources::connectorWidth);

		topConnectorPointLine = arcCenterPoint;
		topConnectorPointLine
			.MoveDownwards(NandGateResources::arcRadius)
				->MoveToRight(NandGateResources::arcRadius);
		topLine = arcCenterPoint;
		topLine.MoveToRight(NandGateResources::arcRadius);

		bottomConnectorPointLine = arcCenterPoint;
		bottomConnectorPointLine
			.MoveDownwards(NandGateResources::arcRadius)
				->MoveToLeft(NandGateResources::arcRadius);
		bottomLine = arcCenterPoint;
		bottomLine.MoveToLeft(NandGateResources::arcRadius);
		GraphicsHelper::DrawArc(arcCenterPoint, NandGateResources::arcStartAngle270, NandGateResources::arcEndAngle270, NandGateResources::arcRadius);
	}
	GraphicsHelper::DrawLine(leftUpperLine, upperLeftPoint);
	GraphicsHelper::DrawLine(bottomLeftPoint, leftLowerLine);
	GraphicsHelper::DrawCircle(circleCenterPoint, NandGateResources::circleRadius);
	GraphicsHelper::DrawLine(middleConnectorPoint, middleConnectorPointLine);
	GraphicsHelper::DrawLine(topConnectorPointLine,	topLine);
	GraphicsHelper::DrawLine(bottomConnectorPointLine, bottomLine);
	GraphicsHelper::DrawLine(topConnectorPointLine, bottomConnectorPointLine);

	PushConnectorPoint(leftLowerLine);
	PushConnectorPoint(middleConnectorPointLine);
	PushConnectorPoint(upperLeftPoint);

}
