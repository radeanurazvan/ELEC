#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h";

static class OperationalAmplifierResources{
private:
	OperationalAmplifierResources();
public:
	static std::string Name;
	static const int TriangleWidth = 15;
	static const int TriangleHeight = 25;
	static const int DistanceBetweenConnectorAndcorner = 7;
	static const int DistanceBetweenSignAndCorner = 10;
	static const int ActualContainerSize = TriangleHeight + 2 * BaseComponentResources::connectorWidth;
};