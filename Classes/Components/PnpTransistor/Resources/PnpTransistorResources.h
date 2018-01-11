#pragma once
#include <string>

static class PnpTransistorResources
{
private:
	PnpTransistorResources();
public:
	static std::string Name;
	static const int Radius = 12;
	static const int DistanceBetweenCondcutors = 15;
	static const int DistanceFromMidPoint = 7;
	static const int Height = 2 * Radius;
	
	static const int DistanceFromaPoint = 10;
	static const int EntriLine = 10;
	static const int TriangleDistance = 4;
};
