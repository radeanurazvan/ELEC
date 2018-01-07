#include "BaseMenuOption.h"
#include "Classes/CartesianPlane/Area/Area.h"

BaseMenuOption::BaseMenuOption(CartesianPoint bottomLeft, CartesianPoint topRight)
{
	BottomLeft = bottomLeft;
	TopRight = topRight;
}

bool BaseMenuOption::IsTargettedByMouseClick(MouseClickPoint mouseClick)
{
	return Area::RectangleArea(BottomLeft, TopRight)->Contains(mouseClick.Point);
}

