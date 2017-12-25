#pragma once
#include "../BaseComponent/BaseComponent.h"

class PnpTransistor :
	public BaseComponent
{
	std::string name = "Tranzistor PNP";
	int numberOfConnectors = 3;
public:
	PnpTransistor();
	void Draw() override;
};
