#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h"

static class NodeResources
{
private:
	NodeResources();
public:
	static std::string Name;
	static const int Radius = 3;
	static const int ActualContainerSize = 2 * Radius + 2 * BaseComponentResources::connectorWidth;
};
