#include "stdafx.h"
#include "Classes/Helpers/CircuitReader/CircuitReader.h"
#include "graphics.h"
#include "Classes/Circuit/Circuit.h"
#include "Classes/Components/Condenser/Condenser.h"


using std::cout;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));

	auto circuit = new Circuit();
	circuit->DrawFromFile("circuit.json");

	getch();
	closegraph();

	return 0;
}
