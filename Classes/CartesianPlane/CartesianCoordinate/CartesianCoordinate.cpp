#include "CartesianCoordinate.h"

CartesianCoordinate::CartesianCoordinate(const int x, const int y)
{
	_x = x;
	_y = y;
}

int CartesianCoordinate::GetX() {
	return _x;
}

void CartesianCoordinate::SetX(int coord) {
	_x = coord;
}

int CartesianCoordinate::GetY() {
	return _y;
}

void CartesianCoordinate::SetY(int coord) {
	_y = coord;
}

