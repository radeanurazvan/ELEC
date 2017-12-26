#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/NandGateResources.h"

class NandGate :
	public BaseComponent
{
	std::string name = NandGateResources::Name;
	int numberOfConnectors = 3;
public:
	NandGate();
	void Draw() override;
};

