#include "FreeDrawMenuOption.h"

FreeDrawMenuOption::FreeDrawMenuOption(const std::string targetComponent, const CartesianPoint bottomLeft, const CartesianPoint topRight)
{
	TargetComponent = targetComponent;
	RectangleBottomLeft = bottomLeft;
	RectangleTopRight = topRight;
}
