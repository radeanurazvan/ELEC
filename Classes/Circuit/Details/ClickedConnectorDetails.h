#pragma once

class ClickedConnectorDetails
{
public:
	ClickedConnectorDetails(std::string _componentId, int _connectorIndex)
	{
		componentId = _componentId;
		connectorIndex = _connectorIndex;
	}

	std::string componentId;
	int connectorIndex;

	bool IsValid()
	{
		return connectorIndex != 0 && componentId != "";
	}

	static ClickedConnectorDetails InvalidClick()
	{
		return ClickedConnectorDetails("", 0);
	}
};