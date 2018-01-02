#include "MenuOption.h"

MenuOption::MenuOption(const std::string targetComponent, const CartesianPoint bottomLeft, const CartesianPoint topRight)
{
	TargetComponent = targetComponent;
	RectangleBottomLeft = bottomLeft;
	RectangleTopRight = topRight;
}
