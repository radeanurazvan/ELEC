#include "OperationalAmplifier.h"
#include "Resources//OprerationalAmplifierResources.h"
#include "../../Helpers/GraphicsHelper/GraphicsHelper.h"
#include "../BaseComponent/Resources/BaseComponentResources.h"

CartesianPoint OperationalAmplifier::GetReferencePoint()
{
	auto referencePoint = BaseComponent::GetReferencePoint();
	referencePoint.MoveToRight(BaseComponentResources::connectorWidth);

	referencePoint.MoveUpwards(BaseComponentResources::connectorWidth);
	return referencePoint;
}

OperationalAmplifier::OperationalAmplifier()
	: BaseComponent(OperationalAmplifierResources::ActualContainerSize)
{
	SetName(name);
}


void OperationalAmplifier::Draw()
{
	auto bottomTriangleCorner = GetReferencePoint();
	auto topTriangleCorner = bottomTriangleCorner;
	auto middleTriangleCorner = bottomTriangleCorner;
	auto topConnectorStart = bottomTriangleCorner;
	auto topConnectorEnd = bottomTriangleCorner;
	auto bottomConnectorStart = bottomTriangleCorner;
	auto bottomConnectorEnd = bottomTriangleCorner;
	auto middleConnectorStart = bottomTriangleCorner;
	auto middleConnectorEnd = bottomTriangleCorner;
	auto minusPoint = bottomTriangleCorner;
	auto plusPoint = bottomTriangleCorner;

	if (orientation == Normal) {
		topTriangleCorner.MoveUpwards(OperationalAmplifierResources::TriangleHeight);
		middleTriangleCorner.Copy(topTriangleCorner)->MoveToRight(OperationalAmplifierResources::TriangleHeight)->MoveDownwards(OperationalAmplifierResources::TriangleHeight / 2);

		topConnectorStart.Copy(topTriangleCorner)->MoveDownwards(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveToLeft(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomTriangleCorner)->MoveUpwards(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveToLeft(BaseComponentResources::connectorWidth);

		middleConnectorStart.Copy(middleTriangleCorner);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveToRight(BaseComponentResources::connectorWidth);

		////minusPoint.Copy(topConnectorStart)->MoveToLeft(OperationalAmplifierResources::DistanceBetweenSignAndCorner)->MoveUpwards(OperationalAmplifierResources::DistanceBetweenSignAndCorner);
		////plusPoint.Copy(bottomConnectorStart)->MoveToLeft(OperationalAmplifierResources::DistanceBetweenSignAndCorner)->MoveDownwards(OperationalAmplifierResources::DistanceBetweenSignAndCorner);
	}
	else if (orientation == Degrees90)
	{
		bottomTriangleCorner.MoveUpwards(OperationalAmplifierResources::TriangleHeight);
		topTriangleCorner.Copy(bottomTriangleCorner)->MoveToRight(OperationalAmplifierResources::TriangleHeight);
		middleTriangleCorner.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2);

		topConnectorStart.Copy(topTriangleCorner)->MoveToLeft(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveUpwards(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomTriangleCorner)->MoveToRight(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveUpwards(BaseComponentResources::connectorWidth);

		middleConnectorStart.Copy(middleTriangleCorner);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveDownwards(BaseComponentResources::connectorWidth);
	}
	else if (orientation == Degrees180)
	{
		topTriangleCorner.MoveToRight(OperationalAmplifierResources::TriangleHeight);
		bottomTriangleCorner.Copy(topTriangleCorner)->MoveUpwards(OperationalAmplifierResources::TriangleHeight);
		middleTriangleCorner.MoveUpwards(OperationalAmplifierResources::TriangleHeight / 2);

		topConnectorStart.Copy(topTriangleCorner)->MoveUpwards(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveToRight(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomTriangleCorner)->MoveDownwards(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveToRight(BaseComponentResources::connectorWidth);

		middleConnectorStart.Copy(middleTriangleCorner);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveToLeft(BaseComponentResources::connectorWidth);
	}
	else if (orientation == Degrees270)
	{
		bottomTriangleCorner.MoveToRight(OperationalAmplifierResources::TriangleHeight);
		middleTriangleCorner.MoveToRight(OperationalAmplifierResources::TriangleHeight / 2)->MoveUpwards(OperationalAmplifierResources::TriangleHeight);

		topConnectorStart.Copy(topTriangleCorner)->MoveToRight(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		topConnectorEnd.Copy(topConnectorStart)->MoveDownwards(BaseComponentResources::connectorWidth);

		bottomConnectorStart.Copy(bottomTriangleCorner)->MoveToLeft(OperationalAmplifierResources::DistanceBetweenConnectorAndcorner);
		bottomConnectorEnd.Copy(bottomConnectorStart)->MoveDownwards(BaseComponentResources::connectorWidth);

		middleConnectorStart.Copy(middleTriangleCorner);
		middleConnectorEnd.Copy(middleConnectorStart)->MoveUpwards(BaseComponentResources::connectorWidth);
	}
	GraphicsHelper::DrawTriangle(bottomTriangleCorner, topTriangleCorner, middleTriangleCorner);
	GraphicsHelper::DrawLine(topConnectorStart, topConnectorEnd);
	GraphicsHelper::DrawLine(bottomConnectorStart, bottomConnectorEnd);
	GraphicsHelper::DrawLine(middleConnectorStart, middleConnectorEnd);
	////GraphicsHelper::DrawCharacter(minusPoint, '-');
	////GraphicsHelper::DrawCharacter(plusPoint, '+');

	PushConnectorPoint(topConnectorEnd);
	PushConnectorPoint(bottomConnectorEnd);
	PushConnectorPoint(middleConnectorEnd);

}
