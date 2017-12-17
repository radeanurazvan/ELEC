#pragma once
#include "../BaseComponent/BaseComponent.h"
class SiNuGate :
	public BaseComponent
{
	std::string name = "Si-Nu Gate";
	int numberOfConnectors = 3;
public:
	SiNuGate();
	void Draw() override;
};

