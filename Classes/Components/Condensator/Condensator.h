#pragma once
#include "../BaseComponent/BaseComponent.h"
class Condensator :	
	public BaseComponent
{
public:
	Condensator();
	~Condensator();
	virtual void Draw();
private:
	std::string name = "Condensator";
	int numberOfConnectors = 2;

};

