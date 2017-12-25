#pragma once
#include <string>

class JsonHelper
{
private:
	JsonHelper();
public:
	template <class T>
	static T  Parse(std::string text);

	template <class T>
	static char Stringify(T object);

};

