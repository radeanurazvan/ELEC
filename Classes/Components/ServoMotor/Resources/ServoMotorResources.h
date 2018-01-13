#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h"

static class ServoMotorResources
{
private: 
	ServoMotorResources();
public:
	static std::string Name;
	static const int Radius = 12;
	static const char Signature = 'M';
	static const int ActualContainerSize = 2 * Radius + 2 * BaseComponentResources::connectorWidth;
};
