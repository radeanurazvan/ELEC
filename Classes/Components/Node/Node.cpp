#include "Node.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NodeResources.h"
Node::Node()
	: BaseComponent(NodeResources::ActualContainerSize)
{
	SetName(name);
}

void Node::Draw()
{
	const auto middlePoint = GetReferencePoint();
	auto endPoint = middlePoint;
	auto startPoint = middlePoint;
	startPoint.MoveToLeft(NodeResources::Radius);
	endPoint.MoveToRight(NodeResources::Radius);
	auto val = NodeResources::Radius;
	while (val)
	{
		GraphicsHelper::DrawCircle(middlePoint, val);
		val--;
	}
	if (orientation == Normal || orientation == Degrees180)
		DrawMiddleConnectors(startPoint, endPoint);
	else
		DrawMiddleConnectors90Degrees(startPoint, endPoint);
}
