#pragma once
#include "../../Classes/CartesianPlane/CartesianPoint/CartesianPoint.h"
#include <vector>
#include "Models/MenuOption/StartMenuOption.h"

class StartMenu
{
private:
	StartMenu();
	static std::vector<StartMenuOption> Options;
	static void WriteButtonText(CartesianPoint bottomLeftButtonCorner, std::string text);
	static void DrawButtons();
	static void GetCoordinates(CartesianPoint upperPoint, CartesianPoint lowerPoint, CartesianPoint midPoint);
public:
	static void Initialise();
};
