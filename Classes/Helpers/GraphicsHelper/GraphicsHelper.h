#pragma once
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"

class GraphicsHelper
{
private:
	GraphicsHelper();
	static CartesianPoint GetViewportCenter();
	static void ComputeCoordinates(CartesianPoint &point);
public:
	static void DrawRectangle(CartesianPoint bottomLeft, CartesianPoint topRight);
	static void DrawLine(CartesianPoint pointA, CartesianPoint pointB);
	static void DrawSegmnentOfWidth(CartesianPoint startingPoint, int width);
	static void DrawSegmnentOfHeight(CartesianPoint startingPoint, int height);
};

