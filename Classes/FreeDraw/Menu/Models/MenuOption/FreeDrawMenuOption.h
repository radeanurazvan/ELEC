#pragma once
#include "../../../../CartesianPlane/CartesianPoint/CartesianPoint.h"
#include "../../../../../BaseMenuOption.h"
#include "../../../../Components/BaseComponent/BaseComponent.h"
#include "../../Classes/Enums/Colors.h";

class FreeDrawMenuOption :
	public BaseMenuOption
{
private:
	void Draw(Colors color);
public:
	FreeDrawMenuOption(BaseComponent* targetComponent, CartesianPoint bottomLeft, CartesianPoint topRight);
	BaseComponent* TargetComponent;
	void DrawComponent();
	void Select();
	void Unselect();
};

