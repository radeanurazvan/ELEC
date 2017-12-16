#pragma once
#include "../BaseComponent/BaseComponent.h"
class OperationalAmplifier :
	public BaseComponent
{
	std::string name = "Operational Amplfier";
	int numberOfConnectors = 3;
public:
	OperationalAmplifier();
	void Draw() override;
};

