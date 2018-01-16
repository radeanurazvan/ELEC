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
	BaseComponent* GetComponentById(std::string id);
	int GetComponentIndexById(std::string id);
	void RefreshViewPort();
	void RemoveComponentLinks(std::string componentId);
public:
	Circuit();
	void LoadFromFile(char* fileName);
	void AddComponent(BaseComponent* component);
	void AddLink(JsonObjects::Link link);
	void RemoveComponent(std::string componentId);
	void RepositionComponent(std::string componentId, CartesianPoint newPoint);
	void MoveComponent(std::string componentId, MouseClickPoint clickPoint);
	bool ComponentsOverlap(BaseComponent* component);
	bool IsComponentClicked(MouseClickPoint click);
	bool IsClickedAroundConnector(MouseClickPoint click);
	void RotateClickedComponent(MouseClickPoint click);
	void SetViewPort(Area* vp);
	ClickedConnectorDetails GetClickedConnectorDetails(CartesianPoint clickPoint);
	std::string GetClickedComponentId(MouseClickPoint click);
	void SetMaximumViewport();
	void Draw();

};

