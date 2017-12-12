#pragma once
#include "../BaseComponent/BaseComponent.h"

class Node :
	public BaseComponent
{
public:
	Node();
	~Node();
	void Draw() override;
private:
	std::string name = "Node";
	int numberOfConnectors = 1;
};

