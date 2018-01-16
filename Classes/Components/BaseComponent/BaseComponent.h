#pragma once
#include <string>
#include "../../CartesianPlane/CartesianCoordinate/CartesianCoordinate.h"
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../Enums/orientation.h"
#include <vector>
#include "Resources/BaseComponentResources.h"
#include "../../CartesianPlane/Area/Area.h"
#include "../../Helpers/DOMHelper/MouseClick/MouseClickPoint.h"

class BaseComponent
{
private:
	void DrawConnectorLines(CartesianPoint leftStart, CartesianPoint leftEnd, CartesianPoint rightStart, CartesianPoint rightEnd);
	std::string id;
protected:
	BaseComponent(const int actualContainerSize);
	BaseComponent();
	std::string name;
	int numberOfConnectors;
	CartesianCoordinate coordinates;
	std::vector<CartesianPoint> connectorPoints;
	void DrawMiddleConnectors(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	void DrawMiddleConnectors90Degrees(CartesianPoint bottomLeftLimit, CartesianPoint topRightLimit);
	virtual CartesianPoint GetReferencePoint();
	Orientation orientation;
	void PushConnectorPoint(CartesianPoint connectorPoint);
	BaseComponentResources resources = BaseComponentResources::GetInstance();
	bool IsTopClicked(CartesianPoint clickPoint);
	bool IsBottomClicked(CartesianPoint clickPoint);
	bool IsLeftClicked(CartesianPoint clickPoint);
	bool IsRightClicked(CartesianPoint clickPoint);
public:
	int GetNumberOfConnectors();
	void SetNumberOfConnectors(int number);
	std::string GetName();
	void SetName(std::string _name);
	CartesianCoordinate GetCoordinates();
	void SetCoordinates(CartesianCoordinate coords);
	void SetOrientation(::Orientation orientation);
	CartesianPoint GetConnector(int index);
	std::vector<CartesianPoint> GetConnectors();
	virtual void Draw() = 0;
	Area* GetContainerArea();
	bool IsClicked(MouseClickPoint click);
	void Rotate();
	std::string GetId();
	void SetId(std::string guid);
	void MoveByClick(CartesianPoint clickPoint);
};
