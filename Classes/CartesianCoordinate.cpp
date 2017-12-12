#include "CartesianCoordinate.h"

CartesianCoordinate::CartesianCoordinate()
{
	x = y = 0;
}


CartesianCoordinate::~CartesianCoordinate()
{
	delete this;
}

int CartesianCoordinate::GetX() {
	return x;
}

void CartesianCoordinate::SetX(int coord) {
	x = coord;
}

int CartesianCoordinate::GetY() {
	return y;
}

void CartesianCoordinate::SetY(int coord) {
	y = coord;
}

