#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h"

static class CondenserResources
{
private:
	CondenserResources();
public:
	static std::string Name;
	static const int spaceBetweenConductors = 10;
	static const int conductorsHeight = 20;
	static const int ActualContainerSize = spaceBetweenConductors + 2 * BaseComponentResources::connectorWidth;
};

