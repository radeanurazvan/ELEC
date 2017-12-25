#include "JsonHelper.h"
#include "../../../3rdParties/json-develop/src/json.hpp"


JsonHelper::JsonHelper()
{
}



template<class T>
T JsonHelper::Parse(std::string text)
{
	return nlohmann::json::parse<T>(text);
}

template<class T>
char JsonHelper::Stringify(T object)
{
	return 0;
}

