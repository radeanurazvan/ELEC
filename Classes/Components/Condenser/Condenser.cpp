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
		leftConductorPointLine.MoveUpwards(CondenserResources::conductorsHeight);
		GraphicsHelper::DrawLine(leftConductorPoint, leftConductorPointLine);
		GraphicsHelper::DrawLine(rightConductorPoint, rightConductorPointLine);

		DrawMiddleConnectors(leftConductorPoint, rightConductorPoint);
	}
<<<<<<< HEAD
	else if (Orientation == Degrees90 || Orientation == Degrees270)
=======
	else if (orientation == Degrees90)
>>>>>>> 40a6dfdd955f80448c1f68d855d53fd57c5b9c1b
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
