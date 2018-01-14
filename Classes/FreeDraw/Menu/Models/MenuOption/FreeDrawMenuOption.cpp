#include "FreeDrawMenuOption.h"
#include "../../Resources/FreeDrawMenuResources.h"
#include "../../../../Helpers/GraphicsHelper/GraphicsHelper.h"

void FreeDrawMenuOption::Draw(Colors color)
{
	GraphicsHelper::SetDrawColor(color);
	DrawComponent();
	GraphicsHelper::SetDrawColor(White);
}

FreeDrawMenuOption::FreeDrawMenuOption(BaseComponent* targetComponent, const CartesianPoint bottomLeft, const CartesianPoint topRight):
	BaseMenuOption(bottomLeft, topRight)
{
	TargetComponent = targetComponent;
}

void FreeDrawMenuOption::DrawComponent()
{
	const CartesianCoordinate componentCoordinates(BottomLeft.GetX() + FreeDrawMenuResources::DistanceFromRectangleLine, BottomLeft.GetY() + FreeDrawMenuResources::DistanceAboveRectangleLine);
	TargetComponent->SetCoordinates(componentCoordinates);
	TargetComponent->Draw();

}

void FreeDrawMenuOption::Select()
{
	Draw(Red);
}

void FreeDrawMenuOption::Unselect()
{
	Draw(White);
}