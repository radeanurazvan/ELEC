#include "PositionDetails.h"

JsonObjects::PositionDetails::PositionDetails()
{
}

void JsonObjects::from_json(const nlohmann::json& j, JsonObjects::PositionDetails& positionDetails)
{
	positionDetails.x = j.at("x").get<int>();
	positionDetails.y = j.at("y").get<int>();
}
