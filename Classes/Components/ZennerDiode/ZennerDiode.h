#pragma once
#include "../BaseComponent/BaseComponent.h"

class ZennerDiode :
	public BaseComponent
{
	std::string name = "ZennerDiode";
	int numberOfConnectors = 2;
public:
	ZennerDiode();
	void Draw() override;
};
