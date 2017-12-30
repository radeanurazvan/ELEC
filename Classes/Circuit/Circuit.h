#pragma once
#include <vector>
#include "../Components/BaseComponent/BaseComponent.h"
#include "../Wrappers/Link/Link.h"
#include "../Wrappers/CircuitDetails/CircuitDetails.h"

class Circuit
{
private:
	std::vector<BaseComponent*> components;
	std::vector<JsonObjects::Link> links;
	void Initialise(JsonObjects::CircuitDetails circuitDetails);
	void DrawComponents();
	void DrawLinks();
	void DrawLinkBetween(JsonObjects::Link link);
public:
	Circuit();
	void DrawFromFile(char* fileName);
};

