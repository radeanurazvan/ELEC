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

bool Area::Overlaps(Area area)
{
	auto topLeft = CartesianPoint(area.bottomLeft.GetX(), area.topRight.GetY());
	auto bottomRight = CartesianPoint(area.topRight.GetX(), area.bottomLeft.GetY());

	return Contains(topLeft) || Contains(bottomRight) || Contains(area.bottomLeft) || Contains(area.topRight);
}
