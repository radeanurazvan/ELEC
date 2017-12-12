#pragma once
#include "..\Classes\Components\BaseComponent\BaseComponents.h"
class Diode :
	public BaseComponent
{
public:
	Diode();
	~Diode();
	virtual void Draw();
private:
	std::string name = "Diode";
	int numberOfConnectors = 2;
};

