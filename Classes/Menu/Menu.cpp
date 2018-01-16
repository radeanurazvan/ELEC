#include "Menu.h"
#include "Resources/MenuResources.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../FreeDraw/FreeDraw.h"
#include "../Circuit/Circuit.h"

std::string Menu::mouseEventSubscriptionId = "";
std::vector<StartMenuOption> Menu::Options;
DOMHelper Menu::domHelper;
void Menu::WriteButtonText(CartesianPoint bottomLeftButtonCorner, std::string text)
{
	bottomLeftButtonCorner
		.MoveUpwards(MenuResources::buttonBottomPadding)
		->MoveToRight(MenuResources::buttonLeftPadding);
	GraphicsHelper::WriteText(bottomLeftButtonCorner, text);
}

void Menu::DrawButtons()
{
	auto mid = GraphicsHelper::GetPlaneCenter();
	mid.MoveToRight(MenuResources::buttonWidth / 2);
	
	auto topButtonBottomLeft = mid;
	auto bottomButtonBottomLeft = mid;

	topButtonBottomLeft.MoveToLeft(MenuResources::buttonWidth);
	auto leftButtonTopRight = topButtonBottomLeft;
	leftButtonTopRight.MoveUpwards(MenuResources::buttonHeight)->MoveToRight(MenuResources::buttonWidth);
	GraphicsHelper::DrawRectangle(topButtonBottomLeft, leftButtonTopRight);
	WriteButtonText(topButtonBottomLeft, MenuResources::freeDrawText);
	Options.push_back(StartMenuOption(MenuResources::freeDrawText, topButtonBottomLeft, leftButtonTopRight));
	
	bottomButtonBottomLeft.MoveToLeft(MenuResources::buttonWidth )
		->MoveDownwards(MenuResources::buttonHeight);
	auto rightButtonTopRight = bottomButtonBottomLeft;
	rightButtonTopRight.MoveUpwards(MenuResources::buttonHeight)->MoveToRight(MenuResources::buttonWidth);
	GraphicsHelper::DrawRectangle(bottomButtonBottomLeft, rightButtonTopRight);
	WriteButtonText(bottomButtonBottomLeft, MenuResources::drawFromFileText);
	Options.push_back(StartMenuOption(MenuResources::drawFromFileText, bottomButtonBottomLeft, rightButtonTopRight));

}

void Menu::SubscribeMouseEvents()
{
	mouseEventSubscriptionId = domHelper.SubscribeOnLeftClick([&](){
		HandleOptionClick(GetClickedOption());
	});
}

std::string Menu::GetClickedOption()
{
	auto mouseClick = domHelper.GetLeftMouseClick();
	if(mouseClick.IsValid())
	{
		for (auto option : Options)
		{
			if (option.IsTargettedByMouseClick(mouseClick))
			{
				return option.TargetDrawOption;
			}
		}
	}
	return "";
}

void Menu::HandleOptionClick(std::string option)
{
	if(option != "")
	{
		auto circuit = Circuit();
		if(option == MenuResources::drawFromFileText)
		{
			circuit.LoadFromFile("circuit.json");
		}
		FreeDraw::Initialise(circuit);

		domHelper.Unsubscribe(mouseEventSubscriptionId);
	}
}

void Menu::Initialise()
{
	DrawButtons();
	SubscribeMouseEvents();
}





