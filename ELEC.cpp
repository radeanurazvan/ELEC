#include "stdafx.h"
#include "graphics.h"
#include "Classes/Menu/Menu.h"
#include "Classes/Helpers/GraphicsHelper/GraphicsHelper.h"


using std::cout;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));

	int horizontalResolution = 0, verticalResolution = 0;
	GraphicsHelper::GetDesktopResolution(horizontalResolution, verticalResolution);
	initwindow(horizontalResolution, verticalResolution, "ELEC");
	Menu::Initialise();

	getch();
	closegraph();

	return 0;
}
