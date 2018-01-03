#include "stdafx.h"
#include "Classes/Helpers/CircuitReader/CircuitReader.h"
#include "graphics.h"
#include "Classes/Circuit/Circuit.h"
#include "Classes/Menu/Menu.h"
#include "Classes/StartMenu/StartMenu.h"


using std::cout;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));
		
		StartMenu firstMenu;
		firstMenu.DrawButtons();
		
		/*auto circuit = new Circuit();
		circuit->DrawFromFile("circuit.json");
	/*
		auto menu = Menu();
		menu.Inititalise();
	*/
	getch();
	closegraph();

	return 0;
}
