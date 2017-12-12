#pragma once
#include "../BaseComponent/BaseComponent.h"

class TranzistorPNP :
	public BaseComponent
{
private:
	std::string name = "Tranzistor PNP";
	int numberOfConnectors = 3;
public:
	TranzistorPNP();
	~TranzistorPNP();
	void Draw() override;
};
