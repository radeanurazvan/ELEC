#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/OprerationalAmplifierResources.h"

class OperationalAmplifier :
	public BaseComponent
{
	std::string name = OperationalAmplifierResources::Name;
	int numberOfConnectors = 3;
	CartesianPoint GetReferencePoint();
public:
	OperationalAmplifier();
	void Draw() override;
};

