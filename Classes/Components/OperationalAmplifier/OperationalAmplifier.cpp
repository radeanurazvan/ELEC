#include "OperationalAmplifier.h"
#include "Resources//OprerationalAmplifierResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../BaseComponent/Resources/BaseComponentResources.h"

OperationalAmplifier::OperationalAmplifier()
{
	SetName(name);
}


void OperationalAmplifier::Draw()
{
	const auto startPoint = GetReferencePoint();
	auto endPoint = startPoint;
	auto pointA = startPoint;
	auto pointB = startPoint;
	auto pointC = startPoint;
	auto line1 = pointA;
	auto line2 = pointC;
	auto endLine = endPoint;
	auto lineOfline1 = line1;
	auto lineOfline2 = line2;
	auto plus = pointA;
	auto minus = pointC;
	auto minusline = minus;
	auto plusline1 = plus;
	auto plusline2 = plus;
	auto line2StartPoint = plusline2;
	if (orientation == Normal) {
		endPoint.MoveToRight(OperationalAmplifierResources::TriangleWidth);

		pointA
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth);
		pointB.MoveToRight(OperationalAmplifierResources::TriangleWidth);
		pointC
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth);

		line1
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth);
		line2
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth);

		lineOfline1
			.MoveToLeft(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);
		lineOfline2
			.MoveToLeft(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);

		endLine.MoveToRight(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth);

		plus
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		minus
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		plusline1
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		minusline
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		plusline2
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);

		line2StartPoint
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 + OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToLeft(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);
	}
	else
	if(orientation == Degrees90)
		{
		endPoint.MoveDownwards(OperationalAmplifierResources::TriangleWidth);

		pointA
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth);
		pointB.MoveDownwards(OperationalAmplifierResources::TriangleWidth);
		pointC
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth);

		line1
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth);
		line2
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth);

		lineOfline1
			.MoveUpwards(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);
		lineOfline2
			.MoveUpwards(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);

		endLine.MoveDownwards(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth);

		plus
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		minus
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		plusline1
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		minusline
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		plusline2
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);

		line2StartPoint
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 + OperationalAmplifierResources::LeftConnectors / 2)
				->MoveUpwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);
		}
	else
	if (orientation == Degrees180)
		{
			endPoint.MoveToLeft(OperationalAmplifierResources::TriangleWidth);

		pointA
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth);
		pointB.MoveToLeft(OperationalAmplifierResources::TriangleWidth);
		pointC
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth);

		line1
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth);
		line2
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth);

		lineOfline1
			.MoveToRight(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);
		lineOfline2
			.MoveToRight(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);

		endLine.MoveToLeft(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth);

		plus
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		minus
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		plusline1
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		minusline
			.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		plusline2
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);

		line2StartPoint
			.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2 + OperationalAmplifierResources::LeftConnectors / 2)
				->MoveToRight(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);	
		}
	else
	if (orientation == Degrees270)
		{
		endPoint.MoveUpwards(OperationalAmplifierResources::TriangleWidth);

		pointA
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth);
		pointB.MoveUpwards(OperationalAmplifierResources::TriangleWidth);
		pointC
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth);

		line1
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth);
		line2
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth);

		lineOfline1
			.MoveDownwards(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);
		lineOfline2
			.MoveDownwards(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth)
				->MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors);

		endLine.MoveUpwards(BaseComponentResources::connectorWidth + OperationalAmplifierResources::TriangleWidth);

		plus
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		minus
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors);

		plusline1
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		minusline
			.MoveToLeft(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors * 2);

		plusline2
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 - OperationalAmplifierResources::LeftConnectors / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);

		line2StartPoint
			.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2 + OperationalAmplifierResources::LeftConnectors / 2)
				->MoveDownwards(OperationalAmplifierResources::TriangleWidth + OperationalAmplifierResources::LeftConnectors + OperationalAmplifierResources::LeftConnectors / 2);
		}
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	GraphicsHelper::DrawLine(endPoint, endLine);
	GraphicsHelper::DrawLine(line1, lineOfline1);
	GraphicsHelper::DrawLine(line2, lineOfline2);
	GraphicsHelper::DrawLine(minus, minusline);
	GraphicsHelper::DrawLine(plus, plusline1);
	GraphicsHelper::DrawLine(line2StartPoint,  plusline2);

	PushConnectorPoint(lineOfline1);
	PushConnectorPoint(lineOfline2);
	PushConnectorPoint(endLine);

}
