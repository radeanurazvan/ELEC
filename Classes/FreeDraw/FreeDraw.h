#pragma once
#include "../Helpers/DOMHelper/DOMHelper.h"
#include "Menu/Models/MenuOption/FreeDrawMenuOption.h"
#include "../Circuit/Circuit.h"

class FreeDraw
{
private:
	FreeDraw();
	static Circuit circuit;
	static std::string componentToDraw;
	static JsonObjects::Link linkToDraw;
	static DOMHelper domHelper;
	static std::string optionsSubscriptionsId;
	static std::string circuitComponentsSubscriptionId;
	static std::string circuitLinksSubscriptionId;
	static void SubscribeToMouseEvents();
	static void BindOptionsEvents();
	static bool TrySelectOption(const MouseClickPoint mouseClick);
	static void BindCircuitEvents();
	static void BindCircuitComponentsEvents();
	static void FireCircuitLeftClickEvents(MouseClickPoint click);
	static void PrepareDrawComponent(std::string targetComponent);
	static void SelectOption(FreeDrawMenuOption option);
	static bool TryDrawNewComponent(CartesianPoint referencePoint);
	static void InitialiseCircuitViewPort();
	static bool ComponentOverlapsOptions(BaseComponent* component);
	static void TryDrawLink(CartesianPoint clickPoint);
public:
	static void Initialise();
	static void Initialise(Circuit circuit);
	~FreeDraw();
};

