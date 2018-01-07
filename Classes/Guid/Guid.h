#pragma once
#include <string>
#include <windows.h>

class Guid
{
private:
	Guid();
	static std::string GuidToString(GUID guid);
public:
	static std::string NewGuid();
};

