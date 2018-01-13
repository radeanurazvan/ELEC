#include "ServoMotor.h"
#include "../../Helpers//GraphicsHelper/GraphicsHelper.h"
#include "Resources/ServoMotorResources.h"

ServoMotor::ServoMotor()
	: BaseComponent(ServoMotorResources::ActualContainerSize)
{
	SetName(name);
}

void ServoMotor::Draw()
{
	const auto startPoint = GetReferencePoint();
	auto drawPoint = startPoint;
	auto connectorStartPoint = startPoint;
	auto connectorEndPoint = startPoint;
		
		drawPoint
			.MoveToLeft(ServoMotorResources::Radius / 2)
				->MoveUpwards(ServoMotorResources::Radius /2);
	
	
	
	GraphicsHelper::DrawCircle(startPoint, ServoMotorResources::Radius);
	GraphicsHelper::DrawCharacter(drawPoint, ServoMotorResources::Signature);
	if (orientation == Normal || orientation == Degrees180)
	{
		connectorStartPoint.MoveToLeft(ServoMotorResources::Radius);
		connectorEndPoint.MoveToRight(ServoMotorResources::Radius);
		DrawMiddleConnectors(connectorStartPoint, connectorEndPoint);
	}
		else
	if (orientation == Degrees90 || orientation == Degrees270)
		{
			connectorStartPoint.MoveUpwards(ServoMotorResources::Radius);
			connectorEndPoint.MoveDownwards(ServoMotorResources::Radius);
			DrawMiddleConnectors90Degrees(connectorStartPoint, connectorEndPoint);
		}
}
