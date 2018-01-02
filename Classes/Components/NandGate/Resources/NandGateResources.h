#pragma once
#include <string>

static class NandGateResources
{
private:
	NandGateResources();
public:
	static std::string Name;
	static const int length = 5;
	static const int height = 20;
	static const int arcStartAngle0 = 270;
	static const int arcEndAngle0 = 90;
	static const int arcStartAngle90 = 180;
	static const int arcEndAngle90 = 0;
	static const int arcStartAngle180 = 90;
	static const int arcEndAngle180 = 270;
	static const int arcStartAngle270 = 0;
	static const int arcEndAngle270 = 180;
	static const int arcRadius = 12;
	static const int distanceBetweenConnectorAndCorner = 7;
	static const int connectorWidth = 7;
	static const int circleRadius = 5;
};
