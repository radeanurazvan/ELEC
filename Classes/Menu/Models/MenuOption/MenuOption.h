#pragma once
#include <string>
#include "../../../CartesianPlane/CartesianPoint/CartesianPoint.h"

class MenuOption
{
public:
	MenuOption(std::string targetComponent, CartesianPoint bottomLeft, CartesianPoint topRight);
	std::string TargetComponent;
	CartesianPoint RectangleBottomLeft;
	CartesianPoint RectangleTopRight;
};

