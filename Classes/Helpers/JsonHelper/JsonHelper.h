#pragma once
#include <string>

class JsonHelper
{
public:
	template <class T>
	static T  Parse(std::string text);
};

