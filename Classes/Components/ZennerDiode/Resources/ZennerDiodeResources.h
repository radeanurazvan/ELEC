#pragma once
#include <string>

static class ZennerDiodeResources
{
private:
	ZennerDiodeResources();
public:
	static std::string Name;
	static const int ConductorHeight = 10;
	static const int ConductorCurveHeight = 4;
	static const int TriangleWidth = 15;
	static const int ConductorCurve = 5;
};
