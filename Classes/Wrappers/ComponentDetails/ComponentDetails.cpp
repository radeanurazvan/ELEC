#include "ComponentDetails.h"

JsonObjects::ComponentDetails::ComponentDetails()
{
}

void JsonObjects::from_json(const nlohmann::json & j, ComponentDetails & componentDetails)
{
	componentDetails.Type = j.at("type").get<std::string>();
	componentDetails.Position = j.at("position").get<PositionDetails>();
	componentDetails.Orientation = j.at("orientation").get<Orientation>();
}
