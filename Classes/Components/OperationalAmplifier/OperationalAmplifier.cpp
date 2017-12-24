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
	GraphicsHelper::DrawSegmnentOfWidth(EndPoint, OperationalAmplifierResources::RightLine);
	GraphicsHelper::DrawSegmnentOfWidth(line1, OperationalAmplifierResources::LeftLine);
	GraphicsHelper::DrawSegmnentOfWidth(line2, OperationalAmplifierResources::LeftLine);
	auto plus = PointA;
	auto minus = PointC;
	plus.MoveToRight(-OperationalAmplifierResources::LeftConnectors);
	minus.MoveDownwards(OperationalAmplifierResources::LeftConnectors / 2);
	minus.MoveToRight(-OperationalAmplifierResources::LeftConnectors);
	GraphicsHelper::DrawSegmnentOfWidth(minus, -OperationalAmplifierResources::LeftConnectors);
	GraphicsHelper::DrawSegmnentOfWidth(plus, -OperationalAmplifierResources::LeftConnectors);
	plus.MoveToRight(-OperationalAmplifierResources::LeftConnectors / 2);
	GraphicsHelper::DrawSegmnentOfHeight(plus, OperationalAmplifierResources::LeftConnectors / 2);
	GraphicsHelper::DrawSegmnentOfHeight(plus, -OperationalAmplifierResources::LeftConnectors / 2);

}
