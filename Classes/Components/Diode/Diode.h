#pragma once
#include "../BaseComponent/BaseComponent.h"

class Diode :
	public BaseComponent
{
public:
	Diode();
	~Diode();
	void Draw() override;
private:
	std::string name = "Diode";
	int numberOfConnectors = 2;
};

