#include "BaseComponentResources.h"

BaseComponentResources::BaseComponentResources()
{
}

BaseComponentResources BaseComponentResources::GetInstance()
{
	static BaseComponentResources instance;;
	return instance;
}
