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
			if(!TrySelectOption(mouseClick))
			{
				DrawNewComponent(mouseClick.Point);
			}
		}
	});
}

bool FreeDraw::TrySelectOption(const MouseClickPoint mouseClick)
{
	for (auto option : FreeDrawMenu::GetOptions())
	{
		if (option.IsTargettedByMouseClick(mouseClick))
		{
			SelectOption(option);
			return true;
		}
	}
	return false;
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

void FreeDraw::DrawNewComponent(CartesianPoint referencePoint)
{
	if(componentToDraw)
	{
		componentToDraw->SetCoordinates(CartesianCoordinate(referencePoint.GetX(), referencePoint.GetY()));
		componentToDraw->Draw();
	}
}

void FreeDraw::Initialise()
{
	FreeDrawMenu::Initialise();
	SubscribeToMouseEvents();
}
