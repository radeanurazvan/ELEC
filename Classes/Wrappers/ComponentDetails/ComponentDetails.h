#pragma once
#include <string>
#include "../PositionDetails/PositionDetails.h"
#include "../../../3rdParties/json-develop/src/json.hpp"
#include "../../Enums/Orientation.h"

namespace JsonObjects
{
	class ComponentDetails
	{
	public:
		ComponentDetails();
		std::string Type;
		PositionDetails Position;
		Orientation Orientation;
	};

	void from_json(const nlohmann::json& j, ComponentDetails& componentDetails);
}
