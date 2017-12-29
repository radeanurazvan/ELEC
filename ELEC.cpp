#include "stdafx.h"
#include "Classes/Helpers/CircuitReader/CircuitReader.h"
#include "Classes/Factories/ComponentFactory/ComponentFactory.h"
#include "graphics.h"
#include "Classes/Components/Resistor/Resistor.h"


using std::cout;
int main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));

	auto circuit = CircuitReader::ReadFromJSON("circuit.json");
	for (auto component : circuit.Components)
	{
		auto instanceOfComponent = ComponentFactory::GetComponentByDetails(component);
		instanceOfComponent->Draw();
	}

	getch();
	closegraph();
	Resistor res;
	res.Draw();

	return 0;
}

