#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h"

static class DiodeResources
{
private:
	DiodeResources();
public:
	static std::string Name;
	static const int ConductorHeight = 15;
	static const int TriangleWidth = 15;
	static const int ActualContainerSize = TriangleWidth + 2 * BaseComponentResources::connectorWidth;
};
