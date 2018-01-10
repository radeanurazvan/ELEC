#include "stdafx.h"
#include "graphics.h"
#include "Classes/Menu/Menu.h"
#include "Classes/Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Classes/Components/Battery/Battery.h"
#include "Classes/Factories/ComponentFactory/ComponentFactory.h"


using std::cout;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, static_cast<char*>(""));

	int horizontalResolution = 0, verticalResolution = 0;
	GraphicsHelper::GetDesktopResolution(horizontalResolution, verticalResolution);
	initwindow(horizontalResolution, verticalResolution, "ELEC");
	////Menu::Initialise();
	auto components = ComponentFactory::GetListOfComponents();
	auto const squareLength = 50;
	for (auto i=0; i<components.size(); i++)
	{
		auto bottomLeft = CartesianPoint(i * squareLength, 0);
		auto component = components.at(i);
		component->SetCoordinates(CartesianCoordinate(bottomLeft.GetX()+1, bottomLeft.GetY()+1));
		GraphicsHelper::DrawRectangle(bottomLeft, CartesianPoint((i + 1)*squareLength, squareLength));
		component->Draw();
	}

	getch();
	closegraph();

	return 0;
}
