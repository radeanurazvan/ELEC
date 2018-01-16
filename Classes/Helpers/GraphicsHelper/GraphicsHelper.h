#pragma once
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../Classes/Enums/Colors.h";
#include "../../CartesianPlane/Area/Area.h";
#include <string>

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
	static void DecomputeCoordinates(CartesianPoint& point);
	static CartesianPoint GetPlaneCenter();
	static void ClearViewPort();
	static void FillRectangle(CartesianPoint bottomLeft, CartesianPoint topRight, int color);
	static void SetDrawColor(Colors color);
	static void SetViewPort(Area* area);
	static void ResetViewPort();
	static Area* GetMaximumViewPort();
};

