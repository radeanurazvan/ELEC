#pragma once
#include "../Helpers/DOMHelper/DOMHelper.h"
#include "Menu/Models/MenuOption/FreeDrawMenuOption.h"

class Circuit;

class FreeDraw
{
private:
	FreeDraw();
	static BaseComponent* componentToDraw;
	static DOMHelper domHelper;
	static std::string optionsSubscriptionsId;
	static std::string circuitComponentsSubscriptionId;
	static std::string circuitLinksSubscriptionId;
	static void SubscribeToMouseEvents();
	static void BindOptionsEvents();
	static void BindCircuitEvents();
	static void BindCircuitComponentsEvents();
	static void BindCircuitLinksEvents();
	static void PrepareDrawComponent(BaseComponent* targetComponent);
	static void SelectOption(FreeDrawMenuOption option);
public:
	static void Initialise();
	static void Initialise(Circuit circuit);
	~FreeDraw();
};

