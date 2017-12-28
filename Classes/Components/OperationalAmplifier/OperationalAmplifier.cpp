#include "OperationalAmplifier.h"
#include "Resources//OprerationalAmplifierResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"

OperationalAmplifier::OperationalAmplifier()
{
}


void OperationalAmplifier::Draw()
{
	const auto startPoint = GetReferencePoint();
	auto endPoint = startPoint;
		endPoint.MoveToRight(OperationalAmplifierResources::TriangleWidth);
	auto pointA = startPoint;
	auto pointB = endPoint;
	auto pointC = startPoint;
		pointA.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2);
		pointC.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2);
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	
	auto line1 = pointA;
	auto line2 = pointC;
		line1.MoveUpwards(OperationalAmplifierResources::LeftConnectors);
		line2.MoveDownwards(OperationalAmplifierResources::LeftConnectors);
	auto endLine = endPoint;
	auto lineOfline1 = line1;
	auto lineOfline2 = line2;
		lineOfline1.MoveToRight(OperationalAmplifierResources::LeftLine);
		lineOfline2.MoveToRight(OperationalAmplifierResources::LeftLine);
		endLine.MoveToRight(OperationalAmplifierResources::RightLine);
	GraphicsHelper::DrawLine(endPoint, endLine);
	GraphicsHelper::DrawLine(line1, lineOfline1);
	GraphicsHelper::DrawLine(line2, lineOfline2);
	
	auto plus = pointA;
	auto minus = pointC;
		plus.MoveToRight(-OperationalAmplifierResources::LeftConnectors);
		minus.MoveDownwards(OperationalAmplifierResources::LeftConnectors / 2);
		minus.MoveToRight(-OperationalAmplifierResources::LeftConnectors);
	auto minusline = minus;
	auto plusline1 = plus;
		plusline1.MoveToRight(-OperationalAmplifierResources::LeftConnectors);
		minusline.MoveToRight(-OperationalAmplifierResources::LeftConnectors);
	GraphicsHelper::DrawLine(minus, minusline);
	GraphicsHelper::DrawLine(plus, plusline1);
	
	plus.MoveToRight(-OperationalAmplifierResources::LeftConnectors / 2);
	auto plusline2 = plus;
		plus.MoveDownwards(OperationalAmplifierResources::LeftConnectors / 2);
		plusline2.MoveUpwards(OperationalAmplifierResources::LeftConnectors);
	GraphicsHelper::DrawLine(plus,  plusline2);


}
