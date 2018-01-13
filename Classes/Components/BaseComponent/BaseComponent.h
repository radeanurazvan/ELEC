#pragma once
#include <string>
#include "../../CartesianPlane/CartesianCoordinate/CartesianCoordinate.h"
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../Enums/orientation.h"
#include <vector>
#include "Resources/BaseComponentResources.h"

class BaseComponent
{
private:
	void DrawConnectorLines(CartesianPoint leftStart, CartesianPoint leftEnd, CartesianPoint rightStart, CartesianPoint rightEnd);
protected:
	BaseComponent(const int actualContainerSize);
	BaseComponent();
	std::string name;
	int numberOfConnectors;
	CartesianCoordinate coordinates;
	std::vector<CartesianPoint> connectorPoints;
	void DrawMiddleConnectors(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	void DrawMiddleConnectors90Degrees(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	CartesianPoint GetReferencePoint();
	Orientation orientation;
	void PushConnectorPoint(CartesianPoint connectorPoint);
	BaseComponentResources resources = BaseComponentResources::GetInstance();
public:
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
