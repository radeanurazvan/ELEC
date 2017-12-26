#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/NodeResources.h"

class Node :
	public BaseComponent
{
public:
	Node();
	void Draw() override;
private:
	std::string name = NodeResources::Name;
	int numberOfConnectors = 1;
};

