#pragma once
#include <string>

static class ServoMotorResources
{
private: 
	ServoMotorResources();
public:
	static std::string Name;
	static const int Radius = 12;
	static const char Signature = 'M';
};
