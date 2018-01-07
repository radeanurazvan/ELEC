#include "StartMenuOption.h"

StartMenuOption::StartMenuOption(std::string targetDrawOption, CartesianPoint botttomLeftPoint, CartesianPoint topRightPoint):
	BaseMenuOption(botttomLeftPoint, topRightPoint)
{
	TargetDrawOption = targetDrawOption;
}
