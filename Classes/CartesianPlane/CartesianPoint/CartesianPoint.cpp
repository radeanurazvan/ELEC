#include "CartesianPoint.h"


CartesianPoint::CartesianPoint(int x, int y)
{
	CartesianCoordinate coordinates(x, y);
	SetCoordinates(coordinates);
}

void CartesianPoint::SetCoordinates(CartesianCoordinate coordinates)
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
