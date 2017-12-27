#pragma once
#include <string>
#include "../../CartesianPlane/CartesianCoordinate/CartesianCoordinate.h"
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../Enums/Orientation.h"

class BaseComponent
{
private:
	std::string name;
	int numberOfConnectors;
	CartesianCoordinate coordinates;
protected:
	void DrawMiddleConnectors(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	CartesianPoint GetReferencePoint();
	Orientation Orientation;
public:
	BaseComponent();
	~BaseComponent();
	int GetNumberOfConnectors();
	void SetNumberOfConnectors(int number);
	std::string GetName();
	void SetName(std::string _name);
	CartesianCoordinate GetCoordinates();
	void SetCoordinates(CartesianCoordinate coords);
	void SetOrientation(::Orientation orientation);
	virtual void Draw() = 0;
};
