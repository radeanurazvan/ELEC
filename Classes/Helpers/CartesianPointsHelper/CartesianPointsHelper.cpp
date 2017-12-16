#include "CartesianPointsHelper.h"


CartesianPointsHelper::CartesianPointsHelper()
{
}

CartesianPoint CartesianPointsHelper::GetMiddlePointBetween(CartesianPoint pointA, CartesianPoint pointB)
{
	const auto middleX = (pointA.GetX() + pointB.GetX()) / 2;
	const auto middleY = (pointA.GetY() + pointB.GetY()) / 2;

	const CartesianPoint middlePoint(middleX, middleY);
	
	return middlePoint;
}
