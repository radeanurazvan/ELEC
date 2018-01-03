#include "StartMenu.h"
#include "../../graphics.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "StartMenuResources/StartMenuResources.h"
#include "../Menu/Menu.h"
#include "../Circuit/Circuit.h"


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
void StartMenu::DrawButtons()
{
	auto midX = getmaxx()/32;
	auto midY = getmaxy()/32;
	char  draw[] = "Free drawing", copy[] = "See a template";
	CartesianPoint mid(midX, midY);
	
	mid.MoveToRight(StartMenuResources::buttonWidth / 2);
	auto leftButton = mid;
	auto rightButton = mid;
	leftButton.MoveToLeft(StartMenuResources::buttonWidth );
	leftButton.MoveUpwards(StartMenuResources::buttonHeight);
	auto leftDraw = leftButton;
	leftDraw.MoveDownwards(StartMenuResources::helpingValue)->MoveToRight(StartMenuResources::helpingValue);
	GraphicsHelper::DrawRectangle(mid, leftButton);
	GraphicsHelper::TextOutPut(leftDraw, draw);
	
	rightButton.MoveToLeft(StartMenuResources::buttonWidth );
	rightButton.MoveDownwards(StartMenuResources::buttonHeight);
	auto rightDraw = rightButton;
	rightDraw.MoveUpwards(StartMenuResources::helpingValue*3)->MoveToRight(StartMenuResources::helpingValue);
	GraphicsHelper::DrawRectangle(rightButton, mid);
	GraphicsHelper::TextOutPut(rightDraw, copy);
	//GetCoordinates(leftDraw,rightDraw,mid);
}



