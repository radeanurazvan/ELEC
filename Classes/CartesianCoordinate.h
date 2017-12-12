#pragma once
class CartesianCoordinate
{	
	private:
		int x, y;
	public:
		CartesianCoordinate();
		~CartesianCoordinate();
		int GetX();
		void SetX(int coord);
		int GetY();
		void SetY(int coord);
};

