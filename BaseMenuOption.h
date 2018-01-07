#pragma once
#include "Classes/CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "Classes/Helpers/DOMHelper/MouseClick/MouseClickPoint.h"

class BaseMenuOption
{
public:
	BaseMenuOption(CartesianPoint bottomLeft, CartesianPoint topRight);
	CartesianPoint BottomLeft;
	CartesianPoint TopRight;
	bool IsTargettedByMouseClick(MouseClickPoint mouseClick);
};

