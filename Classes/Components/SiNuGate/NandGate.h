#pragma once
#include "../BaseComponent/BaseComponent.h"
class NandGate :
	public BaseComponent
{
	std::string name = "NAND Gate";
	int numberOfConnectors = 3;
public:
	NandGate();
	void Draw() override;
};

