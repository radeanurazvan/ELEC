#pragma once
#include "../../Wrappers/CircuitDetails/CircuitDetails.h"

class CircuitReader
{
public:
	static JsonObjects::CircuitDetails ReadFromJSON(char* jsonFile);
};

