#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/BatteryResources.h"

class Battery :
	public BaseComponent
{
	std::string name = BatteryResources::Name;
	int numberOfConnectors = 2;
public:
	Battery();
	void Draw() override;
	void PrepareConnectorPointsForDrawing(CartesianPoint& leftConductorPoint, CartesianPoint& leftConductorPointLine, CartesianPoint& rightConductorPoint, CartesianPoint& rightConductorPointLine);
	void DrawConnectors(CartesianPoint leftConnector, CartesianPoint rightConnector);
};
