#pragma once
#include "../BaseComponent/BaseComponent.h"
class TranzistorNPN :
	public BaseComponent
{
private:
	std::string name = "Tranzistor NPN";
	int numberOfConnectors = 3;
public:
	TranzistorNPN();
	~TranzistorNPN();
	virtual void Draw();
};

