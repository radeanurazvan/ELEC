#pragma once
#include "../../Components/BaseComponent/BaseComponent.h"
#include "../../Wrappers/ComponentDetails/ComponentDetails.h"

class ComponentFactory
{
public:
	static BaseComponent* GetComponentByDetails (const JsonObjects::ComponentDetails details);
};

