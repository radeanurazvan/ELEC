#include "GraphicsHelper.h"
#include "../../graphics.h";
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

void GraphicsHelper::ComputeCoordinates(CartesianPoint& point)
{
	auto center = GetViewportCenter();

	const auto computedX = center.GetX() + point.GetX();
	const auto computedY = center.GetY() - point.GetY();

	const CartesianCoordinate computedCoordinates(computedX, computedY);
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

