#include "ServoMotor.h"
#include "../../Helpers//GraphicsHelper/GraphicsHelper.h"
#include "Resources/ServoMotorResources.h"

ServoMotor::ServoMotor()
{
}

void ServoMotor::Draw()
{
	const auto StartPoint = GetReferencePoint();
	auto DrawPoint = StartPoint;
	DrawPoint.MoveToRight(-ServoMotorResources::Radius / 2);
	DrawPoint.MoveUpwards(-ServoMotorResources::Radius / 2);
	GraphicsHelper::DrawCircle(StartPoint, ServoMotorResources::Radius);
	GraphicsHelper::DrawCharacter(DrawPoint, ServoMotorResources::Signature);
	auto ConnectorStartPoint = StartPoint;
	auto ConnectorEndPoint = StartPoint;
	ConnectorStartPoint.MoveToRight(-ServoMotorResources::Radius);
	ConnectorEndPoint.MoveToRight(ServoMotorResources::Radius);
	DrawMiddleConnectors(ConnectorStartPoint, ConnectorEndPoint);
}
