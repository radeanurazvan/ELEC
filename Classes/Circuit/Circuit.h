#pragma once
#include <vector>
#include "../Components/BaseComponent/BaseComponent.h"
#include "../Wrappers/Link/Link.h"
#include "../Wrappers/CircuitDetails/CircuitDetails.h"
#include "../Helpers/DOMHelper/MouseClick/MouseClickPoint.h"
#include "Details/ClickedConnectorDetails.h"

class Circuit
{
private:
	Area* viewPort;
	std::vector<BaseComponent*> components;
	std::vector<JsonObjects::Link> links;
	void Initialise(JsonObjects::CircuitDetails circuitDetails);
	void DrawComponents();
	void DrawLinks();
	void DrawLinkBetween(JsonObjects::Link link);
	BaseComponent* GetClickedComponent(MouseClickPoint click);
	void RefreshViewPort();
	void Draw();
public:
	Circuit();
	void DrawFromFile(char* fileName);
	void AddComponent(BaseComponent* component);
	void AddLink(JsonObjects::Link link);
	bool ComponentsOverlap(BaseComponent* component);
	bool IsComponentClicked(MouseClickPoint click);
	bool IsClickedAroundConnector(MouseClickPoint click);
	void RotateClickedComponent(MouseClickPoint click);
	void SetViewPort(Area* vp);
	ClickedConnectorDetails GetClickedConnectorDetails(CartesianPoint clickPoint);
};

