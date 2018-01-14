#pragma once
#include <vector>
#include "../Components/BaseComponent/BaseComponent.h"
#include "../Wrappers/Link/Link.h"
#include "../Wrappers/CircuitDetails/CircuitDetails.h"
#include "../Helpers/DOMHelper/MouseClick/MouseClickPoint.h"

class Circuit
{
private:
	std::vector<BaseComponent*> components;
	std::vector<JsonObjects::Link> links;
	void Initialise(JsonObjects::CircuitDetails circuitDetails);
	void DrawComponents();
	void DrawLinks();
	void DrawLinkBetween(JsonObjects::Link link);
	BaseComponent* GetClickedComponent(MouseClickPoint click);
	void Draw();
public:
	Circuit();
	void DrawFromFile(char* fileName);
	void PushComponent(BaseComponent* component);
	bool ComponentsOverlap(BaseComponent* component);
	bool IsComponentClicked(MouseClickPoint click);
	void RotateClickedComponent(MouseClickPoint click);
};

