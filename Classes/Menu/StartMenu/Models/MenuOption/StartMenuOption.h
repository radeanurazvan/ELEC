#pragma once
#include "../../../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include <string>

class StartMenuOption
{
public:
	StartMenuOption(std::string targetDrawOption, CartesianPoint botttomLeftPoint, CartesianPoint topRightPoint);
	std::string TargetDrawOption;
	CartesianPoint BottomLeftPoint;
	CartesianPoint TopRightPoint;
};

