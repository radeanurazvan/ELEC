#pragma once
#include "../../../CartesianPlane/CartesianPoint/CartesianPoint.h"

class MouseClickPoint
{
public:
	MouseClickPoint(int x, int y);
	bool IsValid();
	CartesianPoint Point;
	static MouseClickPoint InvalidClick();
};

