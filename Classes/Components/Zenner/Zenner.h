#pragma once
#include "../BaseComponent/BaseComponent.h"
class Zenner :
	public BaseComponent
{
private:
	std::string name = "Zenner";
	int numberOfConnectors = 2;
public:
	Zenner();
	~Zenner();
	virtual void Draw();
};

