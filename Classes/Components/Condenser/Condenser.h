#pragma once
#include "../BaseComponent/BaseComponent.h"

class Condenser :
	public BaseComponent
{
	std::string name = "Condenser";
	int numberOfConnectors = 2;
public:
	Condenser();
	void Draw() override;
};

