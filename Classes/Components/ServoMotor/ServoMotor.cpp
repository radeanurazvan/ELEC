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
		drawPoint.MoveToRight(-ServoMotorResources::Radius / 2);
		drawPoint.MoveUpwards(-ServoMotorResources::Radius / 2);
	GraphicsHelper::DrawCircle(startPoint, ServoMotorResources::Radius);
	GraphicsHelper::DrawCharacter(drawPoint, ServoMotorResources::Signature);
	
	auto connectorStartPoint = startPoint;
	auto connectorEndPoint = startPoint;
		connectorStartPoint.MoveToRight(-ServoMotorResources::Radius);
		connectorEndPoint.MoveToRight(ServoMotorResources::Radius);
	DrawMiddleConnectors(connectorStartPoint, connectorEndPoint);
}
