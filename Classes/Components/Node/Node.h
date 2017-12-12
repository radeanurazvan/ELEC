#pragma once
#include "..\Classes\Components\BaseComponent\BaseComponent.h"
class Node :
	public BaseComponent
{
public:
	Node();
	~Node();
	virtual void Draw();
private:
	std::string name = "Node";
	int numberOfConnectors = 1;
};

