#include "Node.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NodeResources.h"
Node::Node()
{
}

void Node::Draw()
{
	const auto startPoint = GetReferencePoint();
	auto val = NodeResources::Radius;
	while (val)
	{
		GraphicsHelper::DrawCircle(startPoint, val);
		val--;
	}
	DrawMiddleConnectors(startPoint, startPoint);
}
