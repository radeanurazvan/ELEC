#include "GraphicsHelper.h"
#include "../../graphics.h"
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"

GraphicsHelper::GraphicsHelper()
{
}
CartesianPoint GraphicsHelper::GetViewportCenter()
{
	const auto maxX = getmaxx();
	const auto maxY = getmaxy();
	const CartesianPoint center(maxX / 2, maxY / 2);
	return center;
}
void GraphicsHelper::SetTextAppereance(int font,int direction ,int charsize)
{	
	settextstyle(font, direction, charsize);
}
void GraphicsHelper::WriteText(CartesianPoint point, std::string text)
{
	char charText[255];
	strcpy(charText, text.c_str());
	ComputeCoordinates(point);
	outtextxy(point.GetX(), point.GetY(), charText);
}

void GraphicsHelper::ComputeCoordinates(CartesianPoint& point)
{
	auto center = GetViewportCenter();

	const auto computedX = center.GetX() + point.GetX();
	const auto computedY = center.GetY() - point.GetY();

	const CartesianCoordinate computedCoordinates(computedX, computedY);
	point.SetCoordinates(computedCoordinates);
}

void GraphicsHelper::DecomputeCoordinates(CartesianPoint& point)
{
	auto center = GetViewportCenter();

	const auto decomputedX = point.GetX() - center.GetX();
	const auto decomputedY = -(point.GetY() - center.GetY());

	const CartesianCoordinate computedCoordinates(decomputedX, decomputedY);
	point.SetCoordinates(computedCoordinates);
}

void GraphicsHelper::DrawTriangle(CartesianPoint A, CartesianPoint B, CartesianPoint C)
{
	ComputeCoordinates(A);
	ComputeCoordinates(B);
	ComputeCoordinates(C);
	line(A.GetX(), A.GetY(), B.GetX(), B.GetY());
	line(B.GetX(), B.GetY(), C.GetX(), C.GetY());
	line(C.GetX(), C.GetY(), A.GetX(), A.GetY());
}

void GraphicsHelper::DrawCharacter(CartesianPoint point, char character)
{
	auto center = GetViewportCenter();
	ComputeCoordinates(point);
	auto characterPointer = &character;
	outtextxy(point.GetX(), point.GetY(), characterPointer);
}

void GraphicsHelper::DrawArc(CartesianPoint centerPoint, int startAngle, int endAngle, int radius)
{
	ComputeCoordinates(centerPoint);
	arc(centerPoint.GetX(), centerPoint.GetY(), startAngle, endAngle, radius);
}

int GraphicsHelper::GetWindowWidth()
{
	return getmaxx();
}

int GraphicsHelper::GetMaxX()
{
	return getmaxx() / 2;
}

int GraphicsHelper::GetMaxY()
{
	return getmaxy() / 2;
}

void GraphicsHelper::GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

CartesianPoint GraphicsHelper::GetPlaneCenter()
{
	return CartesianPoint(0, 0);
}

void GraphicsHelper::ClearScreen()
{
	clearviewport();
}

void GraphicsHelper::FillRectangle(CartesianPoint bottomLeft, CartesianPoint topRight, int color)
{
	ComputeCoordinates(bottomLeft);
	ComputeCoordinates(topRight);
	for(int x = bottomLeft.GetX(); x <= topRight.GetX(); x++)
	{
		for(int y = bottomLeft.GetY(); y >= topRight.GetY(); y--)
		{
			putpixel(x, y, color);
		}
	}
}

void GraphicsHelper::SetDrawColor(Colors color)
{
	setcolor(color);
}

void GraphicsHelper::DrawCircle(CartesianPoint midPoint, int radius)
{
	ComputeCoordinates(midPoint);
	circle(midPoint.GetX(), midPoint.GetY(), radius);
}

void GraphicsHelper::DrawRectangle(CartesianPoint bottomLeft, CartesianPoint topRight)
{
	ComputeCoordinates(bottomLeft);
	ComputeCoordinates(topRight);
	rectangle(bottomLeft.GetX(), topRight.GetY(), topRight.GetX(), bottomLeft.GetY());
}

void GraphicsHelper::DrawLine(CartesianPoint pointA, CartesianPoint pointB)
{
	ComputeCoordinates(pointA);
	ComputeCoordinates(pointB);
	line(pointA.GetX(), pointA.GetY(), pointB.GetX(), pointB.GetY());
}

