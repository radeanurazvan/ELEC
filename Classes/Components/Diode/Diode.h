#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/DiodeResources.h"

class Diode :
	public BaseComponent
{
	std::string name = DiodeResources::Name;
	int numberOfConnectors = 2;
public:
	Diode();
	void Draw() override;
};

