#pragma once
#include "..\Classes\Components\BaseComponent\BaseComponent.h"
class Condenser :
	public BaseComponent
{
public:
	Condenser();
	~Condenser();
	virtual void Draw();
private:
	std::string name = "Condenser";
	int numberOfConnectors = 2;
	
};

