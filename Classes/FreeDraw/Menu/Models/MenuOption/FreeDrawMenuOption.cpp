#include "FreeDrawMenuOption.h"
#include "../../Resources/FreeDrawMenuResources.h"
#include "../../../../Helpers/GraphicsHelper/GraphicsHelper.h"

void FreeDrawMenuOption::Draw(int color)
{
	GraphicsHelper::SetDrawColor(color);
	DrawComponent();
	GraphicsHelper::SetDrawColor(1);
}

FreeDrawMenuOption::FreeDrawMenuOption(BaseComponent* targetComponent, const CartesianPoint bottomLeft, const CartesianPoint topRight):
	BaseMenuOption(bottomLeft, topRight)
{
	TargetComponent = targetComponent;
}

void FreeDrawMenuOption::DrawComponent()
{
	const CartesianCoordinate componentCoordinates(TopRight.GetX() + FreeDrawMenuResources::DistanceFromRectangleLine, BottomLeft.GetY() + FreeDrawMenuResources::DistanceAboveRectangleLine);
	TargetComponent->SetCoordinates(componentCoordinates);
	TargetComponent->Draw();

}

void FreeDrawMenuOption::Select()
{
	Draw(4);
}

void FreeDrawMenuOption::Unselect()
{
	Draw(15);
}
