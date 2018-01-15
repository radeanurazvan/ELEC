#include "Link.h"

JsonObjects::Link::Link()
{
}

bool JsonObjects::Link::IsReadyForDrawing()
{
	return FirstComponent != 0 && SecondComponent != 0 && FirstComponentConnector != 0 && SecondComponentConnector != 0;
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
	FirstComponent = FirstComponentConnector = SecondComponent = SecondComponentConnector = 0;
}

bool JsonObjects::Link::IsFirstComponentPopulated()
{
	return FirstComponent > 0 && FirstComponentConnector > 0;
}

bool JsonObjects::Link::IsSecondComponentPopulated()
{
	return SecondComponent > 0 && SecondComponentConnector> 0;
}

void JsonObjects::Link::PopulateFirstComponent(ClickedConnectorDetails clickedConnector)
{
	FirstComponent = clickedConnector.componentIndex;
	FirstComponentConnector = clickedConnector.connectorIndex;
}

void JsonObjects::Link::PopulateSecondComponent(ClickedConnectorDetails clickedConnector)
{
	SecondComponent = clickedConnector.componentIndex;
	SecondComponentConnector = clickedConnector.connectorIndex;
}

void JsonObjects::from_json(const nlohmann::json& j, JsonObjects::Link& link)
{
	link.FirstComponent = j.at("firstComponent").get<int>();
	link.SecondComponent = j.at("secondComponent").get<int>();
	link.FirstComponentConnector = j.at("firstComponentConnector").get<int>();
	link.SecondComponentConnector = j.at("secondComponentConnector").get<int>();
	link.Type = j.at("type").get<LinkType>();
}
