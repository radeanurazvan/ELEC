#pragma once
#include "../BaseComponent/BaseComponent.h"

class Condenser :
	public BaseComponent
{
public:
	Condenser();
	~Condenser();
	void Draw() override;
private:
	std::string name = "Condenser";
	int numberOfConnectors = 2;
	
};

