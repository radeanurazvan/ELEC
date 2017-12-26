#pragma once
#include <string>

static class BatteryResources
{
private:
	BatteryResources();
public:
	static std::string Name;
	static const int spaceBetweenConductors = 10;
	static const int conductorRightHeight = 15;
	static const int conductorLeftHeight = 2 * conductorRightHeight;
};


