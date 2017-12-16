#pragma once
class CartesianCoordinate
{	
	private:
		int _x, _y;
	public:
		CartesianCoordinate(int x = 0, int y = 0);
		int GetX();
		void SetX(int coord);
		int GetY();
		void SetY(int coord);
};

