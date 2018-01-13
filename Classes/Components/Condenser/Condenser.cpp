#include "Condenser.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/CondenserResources.h"


void Condenser::PrepareConnectorPointsForDrawing(CartesianPoint& leftConnectorBottomPoint,
	CartesianPoint& leftConnectorTopPoint, CartesianPoint& rightConnectorBottomPoint,
	CartesianPoint& rightConnectorTopPoint)
{
	auto rightConnectorBottomPointSideDistance = CondenserResources::spaceBetweenConductors;
	auto rightConnectorBottomPointHeightDistance = CondenserResources::conductorsHeight;

	if (orientation == Normal || orientation == Degrees180)
	{
		leftConnectorTopPoint.MoveUpwards(CondenserResources::conductorsHeight);
		rightConnectorBottomPoint.MoveToRight(CondenserResources::spaceBetweenConductors);
		rightConnectorTopPoint.Copy(rightConnectorBottomPoint)->MoveUpwards(CondenserResources::conductorsHeight);
	}
	else if (orientation == Degrees90 || orientation == Degrees270)
	{
		leftConnectorTopPoint.MoveToRight(CondenserResources::conductorsHeight);
		rightConnectorBottomPoint.MoveDownwards(CondenserResources::spaceBetweenConductors);
		rightConnectorTopPoint.Copy(rightConnectorBottomPoint)->MoveToRight(CondenserResources::conductorsHeight);
	}

}

void Condenser::DrawConnectors(CartesianPoint leftConnectorPoint, CartesianPoint rightConnectorPoint)
{
	if(orientation == Normal || orientation == Degrees180)
	{
		DrawMiddleConnectors(leftConnectorPoint, rightConnectorPoint);
	} 
	else
	{
		DrawMiddleConnectors90Degrees(leftConnectorPoint, rightConnectorPoint);

	}
}

Condenser::Condenser()
	: BaseComponent(CondenserResources::ActualContainerSize)
{
	SetName(name);
}


void Condenser::Draw()
{
	auto leftConductorBottomPoint = GetReferencePoint();
	InitLeftConductoBottomPoint(leftConductorBottomPoint);
	auto leftConductorTopPoint = leftConductorBottomPoint;
	auto rightConductorBottomPoint = leftConductorBottomPoint;
	auto rightConductorTopPoint = leftConductorBottomPoint;

	PrepareConnectorPointsForDrawing(leftConductorBottomPoint, leftConductorTopPoint, rightConductorBottomPoint, rightConductorTopPoint);

	DrawConnectors(leftConductorBottomPoint, rightConductorTopPoint);
	GraphicsHelper::DrawLine(leftConductorBottomPoint, leftConductorTopPoint);
	GraphicsHelper::DrawLine(rightConductorBottomPoint, rightConductorTopPoint);
}

void Condenser::InitLeftConductoBottomPoint(CartesianPoint& leftConductorBottomPoint)
{
	if(orientation == Normal || orientation == Degrees180)
	{
		leftConductorBottomPoint.MoveToRight(BaseComponentResources::connectorWidth);
	} else
	{
		leftConductorBottomPoint.MoveUpwards(CondenserResources::spaceBetweenConductors + BaseComponentResources::connectorWidth);
	}
}
