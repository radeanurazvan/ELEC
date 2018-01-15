#pragma once
#include "../../../3rdParties/json-develop/src/json.hpp"
#include "../../Enums/LinkType.h"
#include "../../Circuit/Details/ClickedConnectorDetails.h";

namespace JsonObjects
{
	class Link
	{
	private:
		bool IsFirstComponentPopulated();
		bool IsSecondComponentPopulated();
		void PopulateFirstComponent(ClickedConnectorDetails clickedConnector);
		void PopulateSecondComponent(ClickedConnectorDetails clickedConnector);
	public:
		Link();
		int FirstComponent;
		int SecondComponent;
		int FirstComponentConnector;
		int SecondComponentConnector;
		LinkType Type;
		bool IsReadyForDrawing();
		void Populate(ClickedConnectorDetails clickedConnector);
		void Reset();
	};
	void from_json(const nlohmann::json& j, Link& link);
}

