#pragma once
#include "../BaseComponent/BaseComponent.h"

class Diode :
	public BaseComponent
{
	std::string name = "Diode";
	int numberOfConnectors = 2;
public:
	Diode();
	void Draw() override;
};

