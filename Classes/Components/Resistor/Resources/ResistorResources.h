#pragma once
#include <string>
#include "../../BaseComponent/Resources/BaseComponentResources.h"

static class ResistorResources
{
private:
	ResistorResources();
public:
	static std::string ResistorResources::Name;
	static const int figureWidth = 20;
	static const int figureHeight = 10;
	static const int ActualContainerSize = figureWidth + 2*BaseComponentResources::connectorWidth;
};

