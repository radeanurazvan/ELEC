#pragma once
#include "..\Classes\Components\BaseComponent\BaseComponent.h"
class AmplifierOp :
	public BaseComponent
{
public:
	AmplifierOp();
	~AmplifierOp();
	virtual void Draw();
private:
	std::string name = "AmplifierOp";
	int numberOfConnectors = 3;
};

