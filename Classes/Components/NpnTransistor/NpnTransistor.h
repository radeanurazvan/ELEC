#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/NpnTransistorResources.h"

class NpnTransistor :
	public BaseComponent
{
	std::string name = NpnTransistorResources::Name;
	int numberOfConnectors = 3;
public:
	NpnTransistor();
	void Draw() override;
};

