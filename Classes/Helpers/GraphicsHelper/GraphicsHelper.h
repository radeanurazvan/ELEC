#pragma once
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include <xstring>

class GraphicsHelper
{
private:
	GraphicsHelper();
	static void ComputeCoordinates(CartesianPoint &point);
	static CartesianPoint GetViewportCenter();

public:
	static void DrawRectangle(CartesianPoint bottomLeft, CartesianPoint topRight);
	static void DrawLine(CartesianPoint pointA, CartesianPoint pointB);
	static void DrawTriangle(CartesianPoint pointA, CartesianPoint pointB, CartesianPoint pointC);
	static void DrawCircle(CartesianPoint MidPoint, int radius);
	static void DrawCharacter(CartesianPoint Point, const char character);
	static void DrawArc(CartesianPoint centerPoint, int startAngle, int endAngle, int radius);
	static void WriteText(::CartesianPoint point, std::string text);
	static void SetTextAppereance(int font, int direction, int charsize);
	static int GetWindowWidth();
	static int GetMaxX();
	static int GetMaxY();
	static void GetDesktopResolution(int &horizontal, int &vertical);
	static CartesianPoint GetPlaneCenter();

};

