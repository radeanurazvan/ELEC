#include "ServoMotor.h"
#include "../../Helpers//GraphicsHelper/GraphicsHelper.h"
#include "Resources/ServoMotorResources.h"

ServoMotor::ServoMotor()
{
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
	if (Orientation == Normal || Orientation == Degrees180)
	{
		connectorStartPoint.MoveToLeft(ServoMotorResources::Radius);
		connectorEndPoint.MoveToRight(ServoMotorResources::Radius);
		DrawMiddleConnectors(connectorStartPoint, connectorEndPoint);
	}
		else
	if (Orientation == Degrees90 || Orientation == Degrees270)
		{
			connectorStartPoint.MoveUpwards(ServoMotorResources::Radius);
			connectorEndPoint.MoveDownwards(ServoMotorResources::Radius);
			DrawMiddleConnectors90Degrees(connectorStartPoint, connectorEndPoint);
		}
}
