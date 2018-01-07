#include "MouseClickPoint.h"
#include "Resources/MouseClickResources.h"


MouseClickPoint::MouseClickPoint(int x, int y)
{
	Point = CartesianPoint(x, y);
}

bool MouseClickPoint::IsValid()
{
	return Point.GetX() != MouseClickResources::InvalidClickX && Point.GetY() != MouseClickResources::InvalidClickY;
}

MouseClickPoint MouseClickPoint::InvalidClick()
{
	return MouseClickPoint(MouseClickResources::InvalidClickX, MouseClickResources::InvalidClickY);
}
