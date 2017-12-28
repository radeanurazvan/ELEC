#include "Diode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources//DiodeResources.h"

Diode::Diode()
{
}

void Diode::Draw()
{
	const auto conductorPoint = GetReferencePoint();
	auto conductorPointLine = conductorPoint;
	conductorPointLine.MoveUpwards(DiodeResources::ConductorHeight);
	GraphicsHelper::DrawLine(conductorPoint,conductorPointLine);
		 
	auto endConductorPoint =	conductorPoint;
		 endConductorPoint.MoveToRight(DiodeResources::TriangleWidth);
	auto pointA = conductorPoint;
	auto pointB = endConductorPoint;
	auto pointC = endConductorPoint;
		 pointA.MoveUpwards(DiodeResources::ConductorHeight / 2);
		 pointB.MoveUpwards(DiodeResources::ConductorHeight);
		 pointC.MoveDownwards(DiodeResources::ConductorHeight / 4);
	
	GraphicsHelper::DrawTriangle(pointA, pointB, pointC);
	 endConductorPoint.MoveUpwards(DiodeResources::ConductorHeight);
	 DrawMiddleConnectors(conductorPoint, endConductorPoint);

}
