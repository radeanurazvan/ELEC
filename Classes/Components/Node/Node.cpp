#include "Node.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/NodeResources.h"
Node::Node()
{
	SetName(name);
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
	if (orientation == Normal || orientation == Degrees180)
		DrawMiddleConnectors(startPoint, startPoint);
	else
		DrawMiddleConnectors90Degrees(startPoint, startPoint);
}
