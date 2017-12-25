#pragma once
#include <vector>

#include "../Link/Link.h";
#include "../ComponentDetails/ComponentDetails.h"

class CircuitDetails
{
public:
	std::vector<ComponentDetails> Components;
	std::vector<Link> Links;
};

