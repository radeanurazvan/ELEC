#include "stdafx.h"
#include "3rdParties\json-develop\src\json.hpp"
#include "graphics.h"
#include "winbgi.h"
#include "Classes/Components/Resistor/Resistor.h"
#include "Classes/Components/Condenser/Condenser.h"
#include "Classes/Components/Battery/Battery.h"
#include "Classes/Components/Diode/Diode.h"
#include "Classes/Components/OperationalAmplifier/OperationalAmplifier.h"
#include "Classes/Components/ServoMotor/ServoMotor.h"
#include "Classes/Components/ZennerDiode/ZennerDiode.h"
#include "Classes/Components/NpnTransistor/NpnTransistor.h"

class Battery;
class Diode;
using std::cout;
using json = nlohmann::json;
int main()
{
	json j;
	j.push_back("foo");
	j.push_back(1);
	j.push_back(true);
	
	// also use emplace_back
	j.emplace_back(1.78);

	// iterate the array
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		std::cout << *it << '\n';
	}
   
	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));
	NpnTransistor res;
	res.Draw();
	int xasp, yasp;

	getch();
	closegraph();
	return 0;
}

