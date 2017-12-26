#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/CondenserResources.h"

class Condenser :
	public BaseComponent
{
	std::string name = CondenserResources::Name;
	int numberOfConnectors = 2;
public:
	Condenser();
	void Draw() override;
};

