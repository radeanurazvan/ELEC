#pragma once
#include "c:\Users\Marius\Desktop\ELEC\Classes\Components\BaseComponent\BaseComponent.h"
class Battery :
	public BaseComponent
{
public:
	Battery();
	~Battery();
	virtual void Draw();
 
private:
	std::string name = "Battery";
	int numberofconectors = 2;

};

