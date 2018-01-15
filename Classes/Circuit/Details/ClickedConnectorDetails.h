#pragma once

class ClickedConnectorDetails
{
public:
	ClickedConnectorDetails(int _componentIndex, int _connectorIndex)
	{
		componentIndex = _componentIndex;
		connectorIndex = _connectorIndex;
	}

	int componentIndex;
	int connectorIndex;

	bool IsValid()
	{
		return connectorIndex != 0 && componentIndex != 0;
	}

	static ClickedConnectorDetails InvalidClick()
	{
		return ClickedConnectorDetails(0, 0);
	}
};