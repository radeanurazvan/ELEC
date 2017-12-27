#include "Condenser.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/CondenserResources.h"


Condenser::Condenser()
{
}


void Condenser::Draw()
{
	const auto leftConductorPoint = GetReferencePoint();
	auto rightConductorPoint = GetReferencePoint();

	rightConductorPoint
		.MoveToRight(CondenserResources::spaceBetweenConductors)
		->MoveUpwards(CondenserResources::conductorsHeight);

	GraphicsHelper::DrawLine(leftConductorPoint, CondenserResources::conductorsHeight);
	GraphicsHelper::DrawLine(rightConductorPoint, -CondenserResources::conductorsHeight);

	DrawMiddleConnectors(leftConductorPoint, rightConductorPoint);
}
