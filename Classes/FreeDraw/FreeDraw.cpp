#include "FreeDraw.h"
#include "Menu/FreeDrawMenu.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"


DOMHelper FreeDraw::domHelper;
BaseComponent* FreeDraw::componentToDraw;
std::string FreeDraw::circuitComponentsSubscriptionId;
std::string FreeDraw::optionsSubscriptionsId;
FreeDraw::FreeDraw()
{
}

void FreeDraw::SubscribeToMouseEvents()
{
	BindOptionsEvents();
	BindCircuitEvents();
}

void FreeDraw::BindOptionsEvents()
{
	optionsSubscriptionsId = domHelper.SubscribeOnLeftClick([&]()
	{
		auto mouseClick = domHelper.GetLeftMouseClick();
		if(mouseClick.IsValid())
		{
			for (auto option : FreeDrawMenu::GetOptions())
			{
				if(option.IsTargettedByMouseClick(mouseClick))
				{
					SelectOption(option);
				}
			}
		}
	});
}

void FreeDraw::BindCircuitEvents()
{
	BindCircuitComponentsEvents();
	BindCircuitLinksEvents();
}

void FreeDraw::BindCircuitComponentsEvents()
{
}

void FreeDraw::BindCircuitLinksEvents()
{
}

void FreeDraw::PrepareDrawComponent(BaseComponent* targetComponent)
{
	componentToDraw = targetComponent;
}

void FreeDraw::SelectOption(FreeDrawMenuOption option)
{
	PrepareDrawComponent(option.TargetComponent);
	for (auto menuOption : FreeDrawMenu::GetOptions())
	{
		menuOption.Unselect();
	}
	option.Select();
}

void FreeDraw::Initialise()
{
	FreeDrawMenu::Initialise();
	SubscribeToMouseEvents();
}
