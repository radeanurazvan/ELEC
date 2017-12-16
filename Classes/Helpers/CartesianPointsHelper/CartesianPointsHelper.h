#pragma once
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"

class CartesianPointsHelper
{
private:
	CartesianPointsHelper();
public:
	static CartesianPoint GetMiddlePointBetween(CartesianPoint pointA, CartesianPoint pointB);
};

