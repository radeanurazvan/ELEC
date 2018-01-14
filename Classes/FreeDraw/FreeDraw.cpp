#include "FreeDraw.h"
#include "Menu/FreeDrawMenu.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../Factories/ComponentFactory/ComponentFactory.h"

Circuit FreeDraw::circuit;
DOMHelper FreeDraw::domHelper;
std::string FreeDraw::componentToDraw = "";
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
				TryDrawNewComponent(mouseClick.Point);
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
	domHelper.SubscribeOnRightClick([&]()
	{
		auto click = domHelper.GetRightMouseClick();
		if(circuit.IsComponentClicked(click))
		{
			circuit.RotateClickedComponent(click);
		}
	});
}

void FreeDraw::BindCircuitLinksEvents()
{
}

void FreeDraw::PrepareDrawComponent(std::string targetComponent)
{
	componentToDraw = targetComponent;
}

void FreeDraw::SelectOption(FreeDrawMenuOption option)
{
	PrepareDrawComponent(option.TargetComponent->GetName());
	for (auto menuOption : FreeDrawMenu::GetOptions())
	{
		menuOption.Unselect();
	}
	option.Select();
}

void FreeDraw::TryDrawNewComponent(CartesianPoint referencePoint)
{
	if (componentToDraw != "")
	{
		auto component = ComponentFactory::GetComponentByName(componentToDraw);
		component->SetCoordinates(CartesianCoordinate(referencePoint.GetX(), referencePoint.GetY()));
		if(!circuit.ComponentsOverlap(component))
		{
			circuit.PushComponent(component);
			component->Draw();
		}
	}
}

void FreeDraw::Initialise()
{
	FreeDrawMenu::Initialise();
	SubscribeToMouseEvents();
}
