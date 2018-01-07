#include "Area.h"



Area::Area()
{
}

Area* Area::RectangleArea(CartesianPoint bottomLeft, CartesianPoint topRight)
{
	auto area = new Area();
	area->bottomLeft = bottomLeft;
	area->topRight = topRight;
	return area;
}

bool Area::Contains(CartesianPoint point)
{
	return (point.GetX() >= bottomLeft.GetX() && point.GetX() <= topRight.GetX()) && (point.GetY() >= bottomLeft.GetY() && point.GetY() <= topRight.GetY());
}
