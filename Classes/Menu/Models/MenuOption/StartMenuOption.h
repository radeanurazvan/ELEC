#pragma once
#include <string>
#include "../../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../../../BaseMenuOption.h"

class StartMenuOption :
	public BaseMenuOption
{
public:
	StartMenuOption(std::string targetDrawOption, CartesianPoint botttomLeftPoint, CartesianPoint topRightPoint);
	std::string TargetDrawOption;
};

