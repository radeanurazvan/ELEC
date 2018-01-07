#pragma once
#include "../../Classes/CartesianPlane/CartesianPoint/CartesianPoint.h"
#include <vector>
#include "Models/MenuOption/StartMenuOption.h"
#include "../Helpers/DOMHelper/DOMHelper.h"

class Menu
{
private:
	Menu();
	static std::string mouseEventSubscriptionId;
	static std::vector<StartMenuOption> Options;
	static DOMHelper domHelper;
	static void WriteButtonText(CartesianPoint bottomLeftButtonCorner, std::string text);
	static void DrawButtons();
	static void GetCoordinates(CartesianPoint upperPoint, CartesianPoint lowerPoint, CartesianPoint midPoint);
	static void SubscribeMouseEvents();
	static std::string GetClickedOption();
	static void HandleOptionClick(std::string option);
public:
	static void Initialise();
};
