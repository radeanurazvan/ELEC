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
	if (Orientation == Normal || Orientation ==Degrees180)
	{
		rightConductorPoint
			.MoveToRight(CondenserResources::spaceBetweenConductors)
			->MoveUpwards(CondenserResources::conductorsHeight);

		auto rightConductorPointLine = rightConductorPoint;
		rightConductorPointLine.MoveDownwards(CondenserResources::conductorsHeight);
		auto leftConductorPointLine = leftConductorPoint;
		leftConductorPointLine.MoveUpwards(CondenserResources::conductorsHeight);
		GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);
		GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);

		DrawMiddleConnectors(leftConductorPoint, rightConductorPoint);
	}
	else if (Orientation == Degrees90 || Orientation == Degrees270)
	{
		rightConductorPoint
			.MoveDownwards(CondenserResources::spaceBetweenConductors)
			->MoveToRight(CondenserResources::conductorsHeight);

		auto rightConductorPointLine = rightConductorPoint;
		rightConductorPointLine.MoveToLeft(CondenserResources::conductorsHeight);
		auto leftConductorPointLine = leftConductorPoint;
		leftConductorPointLine.MoveToRight(CondenserResources::conductorsHeight);
		GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);
		GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);
		
		DrawMiddleConnectors90Degrees(leftConductorPoint, rightConductorPoint);
	}

}
