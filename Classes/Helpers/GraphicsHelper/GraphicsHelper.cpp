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

void GraphicsHelper::ComputeCoordinates(CartesianPoint & point)
{
	auto center = GetViewportCenter();

	const auto computedX = center.GetX() + point.GetX();
	const auto computedY = center.GetY() + point.GetY();

	const CartesianCoordinate computedCoordinates(computedX, computedY);
	point.SetCoordinates(computedCoordinates);
}
void GraphicsHelper::DrawTriangle(CartesianPoint A,CartesianPoint B,CartesianPoint C)
{
	auto center = GetViewportCenter();
	ComputeCoordinates(A);
	ComputeCoordinates(B);
	ComputeCoordinates(C);
	line(A.GetX(), A.GetY(), B.GetX(), B.GetY());
	line(B.GetX(), B.GetY(), C.GetX(), C.GetY());
	line(C.GetX(), C.GetY(), A.GetX(), A.GetY());
}
void GraphicsHelper::DrawRectangle(CartesianPoint bottomLeft, CartesianPoint topRight)
{
	auto center = GetViewportCenter();
	ComputeCoordinates(bottomLeft);
	ComputeCoordinates(topRight);
	rectangle(bottomLeft.GetX(), topRight.GetY(), topRight.GetX(), bottomLeft.GetY());
}

void GraphicsHelper::DrawLine(CartesianPoint pointA, CartesianPoint pointB)
{
	line(pointA.GetX(), pointA.GetY(), pointB.GetX(), pointB.GetY());
}

void GraphicsHelper::DrawSegmnentOfWidth(CartesianPoint startingPoint, int width)
{
	auto center = GetViewportCenter();
	CartesianPoint computedPoint(startingPoint.GetX() + width, startingPoint.GetY());

	ComputeCoordinates(startingPoint);
	ComputeCoordinates(computedPoint);

	line(startingPoint.GetX(), startingPoint.GetY(), computedPoint.GetX(), computedPoint.GetY());
}

void GraphicsHelper::DrawSegmnentOfHeight(CartesianPoint startingPoint, int height)
{
	auto center = GetViewportCenter();
	CartesianPoint computedPoint(startingPoint.GetX(), startingPoint.GetY() + height);

	ComputeCoordinates(startingPoint);
	ComputeCoordinates(computedPoint);

	line(startingPoint.GetX(), startingPoint.GetY(), computedPoint.GetX(), computedPoint.GetY());
}
