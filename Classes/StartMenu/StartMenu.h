#pragma once
#include "../../Classes/CartesianPlane/CartesianPoint/CartesianPoint.h"

class StartMenu
{
public:
	static void DrawButtons();
	static void GetCoordinates(CartesianPoint upperPoint, CartesianPoint lowerPoint, CartesianPoint midPoint);
};
