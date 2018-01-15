#pragma once
#include "../CartesianPoint/CartesianPoint.h"

class Area
{
private:
	Area();
	CartesianPoint bottomLeft;
	CartesianPoint topRight;
public:
	static Area* RectangleArea(CartesianPoint bottomLeft, CartesianPoint topRight);
	bool Contains(CartesianPoint point);
	bool Overlaps(Area area);
	CartesianPoint GetBottomLeft();
	CartesianPoint GetTopRight();
};

