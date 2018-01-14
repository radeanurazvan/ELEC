#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/ZennerDiodeResources.h"

class ZennerDiode :
	public BaseComponent
{
	std::string name = ZennerDiodeResources::Name;
	int numberOfConnectors = 2;
	CartesianPoint GetReferencePoint();
public:
	ZennerDiode();
	void Draw() override;
};
