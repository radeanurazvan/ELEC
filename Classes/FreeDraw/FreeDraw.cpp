#include "FreeDraw.h"
#include "Menu/FreeDrawMenu.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../Factories/ComponentFactory/ComponentFactory.h"
#include "Menu/Resources/FreeDrawMenuResources.h"

JsonObjects::Link FreeDraw::linkToDraw;
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
				if(!TryDrawNewComponent(mouseClick.Point))
				{
					FireCircuitLeftClickEvents(mouseClick);
				}
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
			linkToDraw.Reset();
			SelectOption(option);
			return true;
		}
	}
	return false;
}

void FreeDraw::BindCircuitEvents()
{
	BindCircuitComponentsEvents();
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

	domHelper.SubscribeOnMiddleClick([&]()
	{
		auto click = domHelper.GetMiddleClick();
		if(click.IsValid())
		{
			if(circuit.IsComponentClicked(click))
			{
				auto componentId = circuit.GetClickedComponentId(click);
				if(componentId != "")
				{
					circuit.RemoveComponent(componentId);
				}
			}
		}
	});

	////domHelper.SubscribeOnCombination([&]()
	////{
	////	auto mousePosition = domHelper.GetMousePosition();
	////	if(circuit.IsComponentClicked(mousePosition))
	////	{
	////		auto componentId = circuit.GetClickedComponentId(mousePosition);
	////		circuit.RepositionComponent(componentId, mousePosition.Point);
	////	}
	////}, DoubleLeftClick, LeftClick);
}

void FreeDraw::FireCircuitLeftClickEvents(MouseClickPoint click)
{
	if (circuit.IsClickedAroundConnector(click))
	{
		TryDrawLink(click.Point);
	} else
	{
		if (circuit.IsComponentClicked(click))
		{
			auto componentId = circuit.GetClickedComponentId(click);
			circuit.MoveComponent(componentId, click);
		}
	}

	
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

bool FreeDraw::TryDrawNewComponent(CartesianPoint referencePoint)
{
	if (componentToDraw != "")
	{
		auto component = ComponentFactory::GetComponentByName(componentToDraw);
		component->SetCoordinates(CartesianCoordinate(referencePoint.GetX(), referencePoint.GetY()));
		if(!circuit.ComponentsOverlap(component) && !ComponentOverlapsOptions(component))
		{
			circuit.AddComponent(component);
			component->Draw();
			linkToDraw.Reset();
			return true;
		}
	}
	return false;
}

void FreeDraw::InitialiseCircuitViewPort()
{
	auto maximumX = GraphicsHelper::GetMaxX();
	auto maximumY = GraphicsHelper::GetMaxY();
	auto topRight= CartesianPoint(maximumX, maximumY);
	topRight.MoveDownwards(FreeDrawMenuResources::RectangleHeight + 1);

	auto minimumX = -maximumX;
	auto minimumY = -maximumY;
	auto bottomLeft = CartesianPoint(minimumX, minimumY);


	circuit.SetViewPort(Area::RectangleArea(bottomLeft, topRight));
}

bool FreeDraw::ComponentOverlapsOptions(BaseComponent* component)
{
	for (auto option : FreeDrawMenu::GetOptions())
	{
		if(Area::RectangleArea(option.BottomLeft, option.TopRight)->Overlaps(*component->GetContainerArea()))
		{
			return true;
		}
	}
	return false;
}

void FreeDraw::TryDrawLink(CartesianPoint clickPoint)
{
	auto clickedConnectorDetails = circuit.GetClickedConnectorDetails(clickPoint);
	linkToDraw.Populate(clickedConnectorDetails);
	if(linkToDraw.IsReadyForDrawing())
	{
		circuit.AddLink(linkToDraw);
		linkToDraw.Reset();
	}
}

void FreeDraw::Initialise(Circuit _circuit)
{
	circuit = _circuit;
	FreeDrawMenu::Initialise();
	InitialiseCircuitViewPort();
	circuit.Draw();
	SubscribeToMouseEvents();

}
