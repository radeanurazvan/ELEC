#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/ServoMotorResources.h"

class ServoMotor :
	public BaseComponent
{
	std::string name = ServoMotorResources::Name;
	int numberOfConnectors = 2;
	CartesianPoint GetReferencePoint();
public:
	ServoMotor();
	void Draw() override;
};

