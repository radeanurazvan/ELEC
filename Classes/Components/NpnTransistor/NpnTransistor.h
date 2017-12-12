#pragma once
#include "../BaseComponent/BaseComponent.h"
class NpnTransistor :
	public BaseComponent
{
	std::string name = "Tranzistor NPN";
	int numberOfConnectors = 3;
public:
	NpnTransistor();
	void Draw() override;
};

