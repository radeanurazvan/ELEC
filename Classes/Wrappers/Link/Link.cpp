#include "Link.h"

JsonObjects::Link::Link()
{
}

void JsonObjects::from_json(const nlohmann::json& j, JsonObjects::Link& link)
{
	link.FirstComponent = j.at("firstComponent").get<int>();
	link.SecondComponent = j.at("secondComponent").get<int>();
	link.FirstComponentConnector = j.at("firstComponentConnector").get<int>();
	link.SecondComponentConnector = j.at("secondComponentConnector").get<int>();
	link.Type = j.at("type").get<LinkType>();
}
