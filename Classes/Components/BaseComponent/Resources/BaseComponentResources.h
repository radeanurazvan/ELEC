#pragma once
class BaseComponentResources
{
protected:
	BaseComponentResources();
public:
	int maxContainerSize = 50;
	int actualContainerSize;
	static const int connectorWidth = 10;
	static const int connectorErrorMargin = 5;
	static BaseComponentResources GetInstance();
};

