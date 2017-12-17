#pragma once
#include "../CartesianCoordinate/CartesianCoordinate.h";

class CartesianPoint
{
private:
	CartesianCoordinate _coordinates;
public:
	CartesianPoint(int x = 0, int y = 0);
	void SetCoordinates(CartesianCoordinate coordinates);
	int GetX();
	int GetY();
	void MoveToRight(const int distance);
	void MoveUpwards(const int distance);
};

