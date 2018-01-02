#include "Condenser.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources/CondenserResources.h"


Condenser::Condenser()
{
	SetName(name);
}


void Condenser::Draw()
{
	const auto leftConductorPoint = GetReferencePoint();
	auto rightConductorPoint = GetReferencePoint();
	if (orientation == Normal || orientation ==Degrees180)
	{
		rightConductorPoint
			.MoveToRight(CondenserResources::spaceBetweenConductors)
			->MoveUpwards(CondenserResources::conductorsHeight);

		auto rightConductorPointLine = rightConductorPoint;
		rightConductorPointLine.MoveDownwards(CondenserResources::conductorsHeight);
		auto leftConductorPointLine = leftConductorPoint;
		leftConductorPointLine.MoveDownwards(-CondenserResources::conductorsHeight);
		GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);
		GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);

		DrawMiddleConnectors(leftConductorPoint, rightConductorPoint);
	}
	else if (orientation == Degrees90)
	{

	}
	
}
