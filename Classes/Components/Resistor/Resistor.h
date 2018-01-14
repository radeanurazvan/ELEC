#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/ResistorResources.h"

class Resistor : 
	public BaseComponent
{
	std::string name = ResistorResources::Name;
	int numberOfConnectors = 2;
	CartesianPoint GetReferencePoint();
public:
	Resistor();
	void Draw() override;
};
