#pragma once
#include "../../../3rdParties/json-develop/src/json.hpp"
#include "../../Enums/LinkType.h"

namespace JsonObjects
{
	class Link
	{
	public:
		Link();
		int FirstComponent;
		int SecondComponent;
		int FirstComponentConnector;
		int SecondComponentConnector;
		LinkType Type;
	};
	void from_json(const nlohmann::json& j, Link& link);
}

