#include "Diode.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "Resources//DiodeResources.h"

CartesianPoint Diode::GetReferencePoint()
{
	auto referencePoint = BaseComponent::GetReferencePoint();
	if (orientation == Normal || orientation == Degrees180)
	{
		referencePoint.MoveToRight(BaseComponentResources::connectorWidth);
	}
	else
	{
		referencePoint.MoveUpwards(BaseComponentResources::connectorWidth);
	}
	return  referencePoint;
}

Diode::Diode()
	: BaseComponent(DiodeResources::ActualContainerSize)
{
	SetName(name);
}

void Diode::Draw()
{
	auto triangleLeftCorner = GetReferencePoint();
	auto triangleRightCorner = triangleLeftCorner;
	auto triangleMiddleCorner = triangleLeftCorner;
	auto middleConductorBottomPoint = triangleLeftCorner;
	auto middleConductorEndPoint = triangleLeftCorner;

	if (orientation == Normal)
	{
		triangleLeftCorner.MoveUpwards(DiodeResources::TriangleWidth);
		triangleMiddleCorner.MoveToRight(DiodeResources::TriangleWidth);
		middleConductorBottomPoint.Copy(triangleMiddleCorner);
		middleConductorEndPoint.Copy(middleConductorBottomPoint)->MoveUpwards(DiodeResources::TriangleWidth);
		triangleMiddleCorner.MoveUpwards(DiodeResources::TriangleWidth / 2);
		DrawMiddleConnectors(triangleRightCorner, middleConductorEndPoint);
	}
	else if (orientation == Degrees90)
	{
		triangleRightCorner.MoveToRight(DiodeResources::TriangleWidth);
		triangleMiddleCorner.MoveUpwards(DiodeResources::TriangleWidth);
		middleConductorEndPoint.Copy(triangleMiddleCorner);
		middleConductorBottomPoint.Copy(middleConductorEndPoint)->MoveToRight(DiodeResources::TriangleWidth);
		triangleMiddleCorner.MoveToRight(DiodeResources::TriangleWidth / 2);
		DrawMiddleConnectors90Degrees(middleConductorBottomPoint, triangleLeftCorner);
	}
	else if (orientation == Degrees180)
	{
		triangleLeftCorner.MoveToRight(DiodeResources::TriangleWidth);
		triangleMiddleCorner.MoveUpwards(DiodeResources::TriangleWidth / 2);
		triangleRightCorner.Copy(triangleLeftCorner)->MoveUpwards(DiodeResources::TriangleWidth);
		middleConductorEndPoint.Copy(triangleRightCorner)->MoveToLeft(DiodeResources::TriangleWidth);
		middleConductorBottomPoint.Copy(middleConductorEndPoint)->MoveDownwards(DiodeResources::TriangleWidth);
		DrawMiddleConnectors(middleConductorEndPoint, triangleLeftCorner);
	}
	else if (orientation == Degrees270)
	{
		triangleRightCorner.MoveUpwards(DiodeResources::TriangleWidth);
		triangleLeftCorner.Copy(triangleRightCorner)->MoveToRight(DiodeResources::TriangleWidth);
		triangleMiddleCorner.MoveToRight(DiodeResources::TriangleWidth / 2);
		middleConductorBottomPoint.Copy(triangleLeftCorner)->MoveDownwards(DiodeResources::TriangleWidth);
		middleConductorEndPoint.Copy(middleConductorBottomPoint)->MoveToLeft(DiodeResources::TriangleWidth);
		DrawMiddleConnectors90Degrees(triangleRightCorner, middleConductorBottomPoint);
	}

	GraphicsHelper::DrawLine(middleConductorBottomPoint, middleConductorEndPoint);
	GraphicsHelper::DrawTriangle(triangleLeftCorner, triangleRightCorner, triangleMiddleCorner);


}
