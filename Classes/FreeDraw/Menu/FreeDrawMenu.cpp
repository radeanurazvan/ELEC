#include "FreeDrawMenu.h"
#include "../../Factories/ComponentFactory/ComponentFactory.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/FreeDrawMenuResources.h"


std::vector<FreeDrawMenuOption> FreeDrawMenu::Options;

FreeDrawMenu::FreeDrawMenu()
{
}

FreeDrawMenu::~FreeDrawMenu()
{
}

void FreeDrawMenu::DrawSquares()
{
	for (auto option : Options)
	{
		option.DrawComponent();
		GraphicsHelper::DrawRectangle(option.BottomLeft, option.TopRight);
	}
}

void FreeDrawMenu::InitialiseOptions()
{
	auto components = ComponentFactory::GetListOfComponents();
	const auto squareWidth = GraphicsHelper::GetWindowWidth() / components.size();

	const auto rectangleTopRightY = GraphicsHelper::GetMaxY();
	const auto rectangleBottomLeftY = rectangleTopRightY - FreeDrawMenuResources::RectangleHeight;
	const auto bottomLeftStartLine = -(GraphicsHelper::GetWindowWidth() / 2);

	for (auto i = 0; i < components.size(); i++)
	{
		auto component = components.at(i);
		auto bottomLeftX = bottomLeftStartLine + i * squareWidth;
		const CartesianPoint bottomLeft(bottomLeftX, rectangleBottomLeftY);
		const CartesianPoint topRight(bottomLeftX + squareWidth, rectangleTopRightY);
		const FreeDrawMenuOption option(component, bottomLeft, topRight);

		Options.push_back(option);
	}
}

void FreeDrawMenu::Initialise()
{
	GraphicsHelper::ClearScreen();
	InitialiseOptions();
	DrawSquares();
}

std::vector<FreeDrawMenuOption> FreeDrawMenu::GetOptions()
{
	return Options;
}
