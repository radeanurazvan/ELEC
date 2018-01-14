#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/NpnTransistorResources.h"

class NpnTransistor :
	public BaseComponent
{
	std::string name = NpnTransistorResources::Name;
	int numberOfConnectors = 3;
	CartesianPoint GetReferencePoint();
public:
	NpnTransistor();
	void Draw() override;
};

