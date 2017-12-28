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
private:
	void PrepareReferencePointsForDrawing(CartesianPoint rightPoint, CartesianPoint leftPoint);
	void ChangeTheMove(CartesianPoint rightConductorPoint);

};
