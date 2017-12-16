#pragma once
#include "../BaseComponent/BaseComponent.h"

class Resistor : BaseComponent
{
	std::string name = "Resistor";
	int numberOfConnectors = 2;
public:
	Resistor();
	void Draw() override;
};
