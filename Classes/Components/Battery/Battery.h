#pragma once
#include "../BaseComponent/BaseComponent.h"

class Battery :
	public BaseComponent
{
	std::string name = "Battery";
	int numberOfConnectors = 2;
public:
	Battery();
	void Draw() override;
};
