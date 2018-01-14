#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/NandGateResources.h"

class NandGate :
	public BaseComponent
{
	std::string name = NandGateResources::Name;
	int numberOfConnectors = 3;
	CartesianPoint GetReferencePoint();
public:
	NandGate();
	void Draw() override;

};

