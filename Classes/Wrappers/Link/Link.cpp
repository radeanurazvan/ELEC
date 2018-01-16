#include "Link.h"

JsonObjects::Link::Link()
{
}

bool JsonObjects::Link::IsReadyForDrawing()
{
	return FirstComponent != "" && SecondComponent != "" && FirstComponentConnector != 0 && SecondComponentConnector != 0;
}

bool JsonObjects::Link::BelongsTo(std::string componentId)
{
	return FirstComponent == componentId || SecondComponent == componentId;
}

void JsonObjects::Link::Populate(ClickedConnectorDetails clickedConnector)
{
	if(!IsFirstComponentPopulated())
	{
		PopulateFirstComponent(clickedConnector);
	} else
	{
		PopulateSecondComponent(clickedConnector);
	}
}

void JsonObjects::Link::Reset()
{
	FirstComponent = SecondComponent = "";
	FirstComponentConnector = SecondComponentConnector = 0;
}

bool JsonObjects::Link::IsFirstComponentPopulated()
{
	return FirstComponent != "" && FirstComponentConnector > 0;
}

bool JsonObjects::Link::IsSecondComponentPopulated()
{
	return SecondComponent != "" && SecondComponentConnector> 0;
}

void JsonObjects::Link::PopulateFirstComponent(ClickedConnectorDetails clickedConnector)
{
	FirstComponent = clickedConnector.componentId;
	FirstComponentConnector = clickedConnector.connectorIndex;
}

void JsonObjects::Link::PopulateSecondComponent(ClickedConnectorDetails clickedConnector)
{
	SecondComponent = clickedConnector.componentId;
	SecondComponentConnector = clickedConnector.connectorIndex;
}

void JsonObjects::from_json(const nlohmann::json& j, JsonObjects::Link& link)
{
	link.FirstComponent = j.at("firstComponent").get<std::string>();
	link.SecondComponent = j.at("secondComponent").get<std::string>();
	link.FirstComponentConnector = j.at("firstComponentConnector").get<int>();
	link.SecondComponentConnector = j.at("secondComponentConnector").get<int>();
	link.Type = j.at("type").get<LinkType>();
}
