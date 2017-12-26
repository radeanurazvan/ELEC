#include "CircuitDetails.h"

JsonObjects::CircuitDetails::CircuitDetails()
{
}

void JsonObjects::from_json(const nlohmann::json& j, JsonObjects::CircuitDetails& circuitDetails)
{
	circuitDetails.Components = j.at("components").get<std::vector<ComponentDetails>>();
	circuitDetails.Links = j.at("links").get<std::vector<Link>>();
}
