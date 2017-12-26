#include "JsonHelper.h"
#include "../../../3rdParties/json-develop/src/json.hpp"

template<class T>
T JsonHelper::Parse(std::string text)
{
	auto json = nlohmann::json::parse(text);
	return json.get<T>();
}

