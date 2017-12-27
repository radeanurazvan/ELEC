#include "Node.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NodeResources.h"
Node::Node()
{
}

void Node::Draw()
{
	const auto StartPoint = GetReferencePoint();
	auto Val = NodeResources::Radius;
	while (Val)
	{
		GraphicsHelper::DrawCircle(StartPoint, Val);
		Val--;
	}
	DrawMiddleConnectors(StartPoint, StartPoint);
}
