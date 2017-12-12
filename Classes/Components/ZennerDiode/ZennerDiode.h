#pragma once
#include "../BaseComponent/BaseComponent.h"

class Zenner :
	public BaseComponent
{
	std::string name = "Zenner";
	int numberOfConnectors = 2;
public:
	Zenner();
	~Zenner();
	void Draw() override;
};
