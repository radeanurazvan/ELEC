#pragma once
#include <string>
#include "../../CartesianPlane/CartesianCoordinate/CartesianCoordinate.h"
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../Enums/Orientation.h"
#include <vector>

class BaseComponent
{
private:
	std::string name;
	int numberOfConnectors;
	CartesianCoordinate coordinates;
	std::vector<CartesianPoint> connectorPoints;
	void DrawConnectorLines(CartesianPoint leftStart, CartesianPoint leftEnd, CartesianPoint rightStart, CartesianPoint rightEnd);
protected:
	void DrawMiddleConnectors(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	void DrawMiddleConnectors90Degrees(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	CartesianPoint GetReferencePoint();
	Orientation Orientation;
	void PushConnectorPoint(CartesianPoint connectorPoint);
public:
	BaseComponent();
	int GetNumberOfConnectors();
	void SetNumberOfConnectors(int number);
	std::string GetName();
	void SetName(std::string _name);
	CartesianCoordinate GetCoordinates();
	void SetCoordinates(CartesianCoordinate coords);
	void SetOrientation(::Orientation orientation);
	CartesianPoint GetConnector(int index);
	virtual void Draw() = 0;
};
