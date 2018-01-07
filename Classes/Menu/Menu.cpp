#include "Menu.h"
#include "Resources/MenuResources.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../CartesianPlane/Area/Area.h"
#include "../FreeDraw/FreeDraw.h"
#include "../Circuit/Circuit.h"


/*void Menu::GetCoordinates(CartesianPoint upperPoint, CartesianPoint lowerPoint, CartesianPoint midPoint)
{
	int x, y;
	while (ismouseclick(WM_LBUTTONDOWN))
	{
		break;
	}
	getmouseclick(WM_LBUTTONDOWN, x, y);
	if (x >= lowerPoint.GetX() && x <= midPoint.GetX())
	{
		if (y >= upperPoint.GetY() && y < midPoint.GetY())
		{
			int gd = DETECT, gm;
			initgraph(&gd, &gm, static_cast<char*>(""));

			auto menu = Menu();
			menu.Inititalise();

			getch();
			closegraph();
		}
		else
			if (y >= midPoint.GetY() && y <= lowerPoint.GetY())
			{
				int gd = DETECT, gm;
				initgraph(&gd, &gm, static_cast<char*>(""));

				auto circuit = new Circuit();
				circuit->DrawFromFile("circuit.json");

				getch();
				closegraph();
			}
	}
}
*/
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
	auto a = mouseEventSubscriptionId;
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
		if(option == MenuResources::freeDrawText)
		{
			FreeDraw::Initialise();
		} else
		{
			Circuit().DrawFromFile("circuit.json");
		}
		domHelper.Unsubscribe(mouseEventSubscriptionId);
	}
}

void Menu::Initialise()
{
	DrawButtons();
	SubscribeMouseEvents();
}





