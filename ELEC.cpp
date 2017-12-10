#include "stdafx.h"
#include "3rdParties\json-develop\src\json.hpp"
#include "graphics.h"
#include "winbgi.h"

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
	initgraph(&gd, &gm, (char*)"");

	int x = 320, y = 240, r;
	for (r = 25; r <= 125; r += 20)
		circle(x, y, r);

	getch();
	closegraph();
	return 0;
}

