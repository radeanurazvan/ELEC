#pragma once
#include <string>
static class OperationalAmplifierResources{
private:
	OperationalAmplifierResources();
public:
	static std::string Name;
	static const int TriangleWidth = 15;
	static const int TriangleHeight = 25;
	static const int LeftConnectors = 4;
	static const int ActualContainerSize = TriangleHeight + 2 * BaseComponentResources::connectorWidth;
};