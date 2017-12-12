#pragma once
#include "..\Classes\Components\BaseComponent\BaseComponent.h"
class Battery :
	public BaseComponent
{
public:
	Battery();
	~Battery();
	virtual void Draw();
 
private:
	std::string name = "Battery";
	int numberOfConnectors = 2;

};

