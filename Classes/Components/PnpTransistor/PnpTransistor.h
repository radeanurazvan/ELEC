#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/PnpTransistorResources.h"

class PnpTransistor :
	public BaseComponent
{
	std::string name = PnpTransistorResources::Name;
	int numberOfConnectors = 3;
	CartesianPoint GetReferencePoint();
public:
	PnpTransistor();
	void Draw() override;
};
