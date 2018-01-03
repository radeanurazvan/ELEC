#pragma once
#include <vector>
#include "../Link/Link.h"
#include "../ComponentDetails/ComponentDetails.h"

namespace JsonObjects {
	class CircuitDetails
	{
	public:
		CircuitDetails();
		std::vector<ComponentDetails> Components;
		std::vector<Link> Links;
	};
	void from_json(const nlohmann::json& j, JsonObjects::CircuitDetails& circuitDetails);
}