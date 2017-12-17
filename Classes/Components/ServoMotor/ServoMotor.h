#pragma once
#include "../BaseComponent/BaseComponent.h"
class ServoMotor :
	public BaseComponent
{
	std::string name = "ServoMotor";
	int numberOfConnectors = 2;
public:
	ServoMotor();
	void Draw() override;
};

