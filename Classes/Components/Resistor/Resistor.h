#pragma once
#include "../BaseComponent/BaseComponent.h"
class Resistor : BaseComponent
{
private:
	std::string name = "Resistor";
	int numberOfConnectors = 2;
public:
	Resistor();
	~Resistor();
	virtual void Draw();
};

