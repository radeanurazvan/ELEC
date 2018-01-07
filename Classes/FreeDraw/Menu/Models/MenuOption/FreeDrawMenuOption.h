#pragma once
#include "../../../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../../../../BaseMenuOption.h"
#include "../../../../Components/BaseComponent/BaseComponent.h"

class FreeDrawMenuOption :
	public BaseMenuOption
{
private:
	void Draw(int color);
public:
	FreeDrawMenuOption(BaseComponent* targetComponent, CartesianPoint bottomLeft, CartesianPoint topRight);
	BaseComponent* TargetComponent;
	void DrawComponent();
	void Select();
	void Unselect();
};

