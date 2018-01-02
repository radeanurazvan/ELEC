#include "Menu.h"
#include "../Factories/ComponentFactory/ComponentFactory.h"
#include "../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/MenuResources.h"


std::vector<MenuOption> Menu::Options;
Menu::Menu()
{
}

void Menu::InitialiseFreeDrawOptions()
{
	auto components = ComponentFactory::GetListOfComponents();
	auto squareWidth = GraphicsHelper::GetWindowWidth() / components.size();

	auto rectangleTopRightY = GraphicsHelper::GetMaxY();
	auto rectangleBottomLeftY = rectangleTopRightY - MenuResources::RectangleHeight;
	auto bottomLeftStartLine = -(GraphicsHelper::GetWindowWidth() / 2);

	for (auto i = 0; i < components.size(); i++)
	{
		auto component = components.at(i);
		auto bottomLeftX = bottomLeftStartLine + i * squareWidth;
		CartesianPoint bottomLeft(bottomLeftX, rectangleBottomLeftY);
		CartesianPoint topRight(bottomLeftX + squareWidth, rectangleTopRightY);
		const MenuOption option(component->GetName(), bottomLeft, topRight);

		Options.push_back(option);
	}
}

void Menu::DrawSquares()
{
	for (auto i = 0; i < Options.size(); i++)
	{
		auto option = Options.at(i);
		auto component = ComponentFactory::GetComponentByName(option.TargetComponent);
		CartesianCoordinate componentCoordinates(option.RectangleBottomLeft.GetX() + MenuResources::DistanceFromRectangleLine, option.RectangleBottomLeft.GetY() + MenuResources::DistanceAboveRectangleLine);
		component->SetCoordinates(componentCoordinates);
		GraphicsHelper::DrawRectangle(option.RectangleBottomLeft, option.RectangleTopRight);
		component->Draw();
	}
}

void Menu::Inititalise()
{
	InitialiseFreeDrawOptions();
	DrawSquares();
}
