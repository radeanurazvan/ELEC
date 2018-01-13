#include "CartesianPoint.h"


CartesianPoint::CartesianPoint(const int x, const int y)
{
	const CartesianCoordinate coordinates(x, y);
	SetCoordinates(coordinates);
}

void CartesianPoint::SetCoordinates(const CartesianCoordinate coordinates)
{
	_coordinates = coordinates;
}

int CartesianPoint::GetX()
{
	return _coordinates.GetX();
}

int CartesianPoint::GetY()
{
	return _coordinates.GetY();
}

CartesianPoint * CartesianPoint::MoveToRight(const int distance)
{
	_coordinates.SetX(_coordinates.GetX() + distance);
	return this;
}

CartesianPoint* CartesianPoint::MoveUpwards(const int distance)
{
	_coordinates.SetY(_coordinates.GetY() + distance);
	return this;
}

CartesianPoint* CartesianPoint::MoveDownwards(const int distance)
{
	_coordinates.SetY(_coordinates.GetY() - distance);
	return this;
}

CartesianPoint* CartesianPoint::MoveToLeft(const int distance)
{
	_coordinates.SetX(_coordinates.GetX() - distance);
	return this;
}

CartesianPoint* CartesianPoint::MoveToSide(const int distance)
{
	_coordinates.SetX(_coordinates.GetX() + distance);
	return this;
}

CartesianPoint* CartesianPoint::MoveInHeight(const int distance)
{
	_coordinates.SetY(_coordinates.GetY() + distance);
	return this;
}

CartesianPoint * CartesianPoint::Copy(CartesianPoint pointToCopy)
{
	_coordinates.SetX(pointToCopy.GetX());
	_coordinates.SetY(pointToCopy.GetY());
	return this;
}
