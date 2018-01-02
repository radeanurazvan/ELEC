#include "stdafx.h"
#include "Classes/Helpers/CircuitReader/CircuitReader.h"
#include "graphics.h"
#include "Classes/Circuit/Circuit.h"
#include "Classes/Menu/Menu.h"


using std::cout;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));

	Menu::Inititalise();

	auto circuit = new Circuit();
	circuit->DrawFromFile("circuit.json");
	getch();
	closegraph();

	return 0;
}
