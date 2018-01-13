#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h"

class BatteryResources
	: public BaseComponentResources
{
private:
	BatteryResources();
public:
	static std::string Name;
	static const int actualContainerSize = 30;
	static const int spaceBetweenConductors = 10;
	static const int rightConductorHeight = 15;
	static const int leftConductorHeight = 2 * rightConductorHeight;
};


