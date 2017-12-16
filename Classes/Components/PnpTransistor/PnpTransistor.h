#pragma once
#include "../BaseComponent/BaseComponent.h"

class TranzistorPNP :
	public BaseComponent
{
	std::string name = "Tranzistor PNP";
	int numberOfConnectors = 3;
public:
	TranzistorPNP();
	void Draw() override;
};
