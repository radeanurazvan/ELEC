#include "OperationalAmplifier.h"
#include "Resources//OprerationalAmplifierResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"

OperationalAmplifier::OperationalAmplifier()
{
}


void OperationalAmplifier::Draw()
{
	const auto StartPoint = GetReferencePoint();
	auto EndPoint = StartPoint;
		EndPoint.MoveToRight(OperationalAmplifierResources::TriangleWidth);
	auto PointA = StartPoint;
	auto PointB = EndPoint;
	auto PointC = StartPoint;
		PointA.MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2);
		PointC.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2);
	GraphicsHelper::DrawTriangle(PointA, PointB, PointC);
	
	auto line1 = PointA;
	auto line2 = PointC;
		line1.MoveUpwards(OperationalAmplifierResources::LeftConnectors);
		line2.MoveDownwards(OperationalAmplifierResources::LeftConnectors);
	auto EndLine = EndPoint;
	auto LineOfline1 = line1;
	auto LineOfline2 = line2;
		LineOfline1.MoveToRight(OperationalAmplifierResources::LeftLine);
		LineOfline2.MoveToRight(OperationalAmplifierResources::LeftLine);
		EndLine.MoveToRight(OperationalAmplifierResources::RightLine);
	GraphicsHelper::DrawLine(EndPoint, EndLine);
	GraphicsHelper::DrawLine(line1, LineOfline1);
	GraphicsHelper::DrawLine(line2, LineOfline2);
	
	auto plus = PointA;
	auto minus = PointC;
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
