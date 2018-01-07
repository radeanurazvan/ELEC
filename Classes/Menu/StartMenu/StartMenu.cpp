#include "StartMenu.h"
#include "StartMenuResources/StartMenuResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../../Helpers/DOMHelper/DOMHelper.h"
#include "../../CartesianPlane/Area/Area.h"
#include "../FreeDrawMenu/FreeDrawMenu.h"
#include "../../Circuit/Circuit.h"


/*void StartMenu::GetCoordinates(CartesianPoint upperPoint, CartesianPoint lowerPoint, CartesianPoint midPoint)
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
std::string StartMenu::mouseEventSubscriptionId = "";
std::vector<StartMenuOption> StartMenu::Options;
DOMHelper StartMenu::domHelper;
void StartMenu::WriteButtonText(CartesianPoint bottomLeftButtonCorner, std::string text)
{
	bottomLeftButtonCorner
		.MoveUpwards(StartMenuResources::buttonBottomPadding)
		->MoveToRight(StartMenuResources::buttonLeftPadding);
	GraphicsHelper::WriteText(bottomLeftButtonCorner, text);
}

void StartMenu::DrawButtons()
{
	auto mid = GraphicsHelper::GetPlaneCenter();
	mid.MoveToRight(StartMenuResources::buttonWidth / 2);
	
	auto topButtonBottomLeft = mid;
	auto bottomButtonBottomLeft = mid;

	topButtonBottomLeft.MoveToLeft(StartMenuResources::buttonWidth);
	auto leftButtonTopRight = topButtonBottomLeft;
	leftButtonTopRight.MoveUpwards(StartMenuResources::buttonHeight)->MoveToRight(StartMenuResources::buttonWidth);
	GraphicsHelper::DrawRectangle(topButtonBottomLeft, leftButtonTopRight);
	WriteButtonText(topButtonBottomLeft, StartMenuResources::freeDrawText);
	Options.push_back(StartMenuOption(StartMenuResources::freeDrawText, topButtonBottomLeft, leftButtonTopRight));
	
	bottomButtonBottomLeft.MoveToLeft(StartMenuResources::buttonWidth )
		->MoveDownwards(StartMenuResources::buttonHeight);
	auto rightButtonTopRight = bottomButtonBottomLeft;
	rightButtonTopRight.MoveUpwards(StartMenuResources::buttonHeight)->MoveToRight(StartMenuResources::buttonWidth);
	GraphicsHelper::DrawRectangle(bottomButtonBottomLeft, rightButtonTopRight);
	WriteButtonText(bottomButtonBottomLeft, StartMenuResources::drawFromFileText);
	Options.push_back(StartMenuOption(StartMenuResources::drawFromFileText, bottomButtonBottomLeft, rightButtonTopRight));

}

void StartMenu::SubscribeMouseEvents()
{
	mouseEventSubscriptionId = domHelper.SubscribeOnClick([&](){
		HandleOptionClick(GetClickedOption());
	});
	auto a = mouseEventSubscriptionId;
}

std::string StartMenu::GetClickedOption()
{
	auto mouseClick = domHelper.GetLeftMouseClick();
	if(domHelper.IsValidMouseClick(mouseClick))
	{
		for (auto option : Options)
		{
			if (Area::RectangleArea(option.BottomLeftPoint, option.TopRightPoint)->Contains(mouseClick))
			{
				return option.TargetDrawOption;
			}
		}
	}
	return "";
}

void StartMenu::HandleOptionClick(std::string option)
{
	if(option != "")
	{
		if(option == StartMenuResources::freeDrawText)
		{
			FreeDrawMenu::Initialise();
		} else
		{
			Circuit().DrawFromFile("circuit.json");
		}
		domHelper.Unsubscribe(mouseEventSubscriptionId);
	}
}

void StartMenu::Initialise()
{
	DrawButtons();
	SubscribeMouseEvents();
}





