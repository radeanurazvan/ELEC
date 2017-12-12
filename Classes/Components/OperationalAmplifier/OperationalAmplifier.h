#pragma once
#include "../BaseComponent/BaseComponent.h"
class OperationalAmplifier :
	public BaseComponent
{
public:
	OperationalAmplifier();
	~OperationalAmplifier();
	void Draw() override;
private:
	std::string name = "AmplifierOp";
	int numberOfConnectors = 3;
};

