#pragma once
#include "../BaseComponent/BaseComponent.h"
#include "Resources/CondenserResources.h"

class Condenser :
	public BaseComponent
{
	std::string name = CondenserResources::Name;
	int numberOfConnectors = 2;
	void InitLeftConductoBottomPoint(CartesianPoint& leftConductorBottomPoint);
	void PrepareConnectorPointsForDrawing(CartesianPoint& leftConnectorBottomPoint, CartesianPoint& leftConnectorTopPoint, CartesianPoint& rightConnectorBottomPoint, CartesianPoint& rightConnectorTopPoint);
	void DrawConnectors(CartesianPoint leftConnectorPoint, CartesianPoint rightConnectorPoint);
public:
	Condenser();
	void Draw() override;
};

