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
	auto rectangleHeight = TopRight.GetY() - BottomLeft.GetY();
	auto rectangleWidth = TopRight.GetX() - BottomLeft.GetX();
	auto topPadding = rectangleHeight - BaseComponentResources::GetInstance().maxContainerSize;
	auto leftPadding = rectangleWidth - BaseComponentResources::GetInstance().maxContainerSize * 2;

	const CartesianCoordinate componentCoordinates(BottomLeft.GetX() + leftPadding, BottomLeft.GetY() + topPadding);
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
