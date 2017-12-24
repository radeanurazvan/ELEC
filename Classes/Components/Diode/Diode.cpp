#include "Diode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources//DiodeResources.h"

Diode::Diode()
{
}

void Diode::Draw()
{
	const auto ConductorPoint = GetReferencePoint();
	GraphicsHelper::DrawSegmnentOfHeight(ConductorPoint,DiodeResources::ConductorHeight);
		 auto EndConductorPoint =	ConductorPoint;
		 EndConductorPoint.MoveToRight(DiodeResources::TriangleWidth);
		 auto PointA = ConductorPoint;
		 auto PointB = EndConductorPoint;
		 auto PointC = EndConductorPoint;
		 PointA.MoveUpwards(DiodeResources::ConductorHeight / 2);
		 PointB.MoveUpwards(DiodeResources::ConductorHeight);
		 PointC.MoveDownwards(DiodeResources::ConductorHeight / 4);
	 GraphicsHelper::DrawTriangle(PointA, PointB, PointC);
	 EndConductorPoint.MoveUpwards(DiodeResources::ConductorHeight);
	 DrawMiddleConnectors(ConductorPoint, EndConductorPoint);

}
