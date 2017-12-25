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
	static void DrawTriangle(CartesianPoint pointA, CartesianPoint pointB, CartesianPoint pointC);
	static void DrawCircle(CartesianPoint MidPoint, int radius);
	static void DrawCharacter(CartesianPoint Point, const char character);
	static void DrawArc(CartesianPoint centerPoint, int startAngle, int endAngle, int radius);
};

