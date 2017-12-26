#pragma once
#include "../../../3rdParties/json-develop/src/json.hpp"

namespace JsonObjects
{
	class PositionDetails
	{
	public:
		PositionDetails();
		int x;
		int y;
	};
	void from_json(const nlohmann::json& j, PositionDetails& positionDetails);

}

