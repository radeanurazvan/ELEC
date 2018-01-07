#pragma once
#include <vector>
#include "Models/MenuOption/FreeDrawMenuOption.h"

class FreeDrawMenu
{
private:
	FreeDrawMenu();
	static std::vector<FreeDrawMenuOption> Options;
	static void DrawSquares();
	static void InitialiseOptions();
public:
	~FreeDrawMenu();
	static void Initialise();
	static std::vector<FreeDrawMenuOption> GetOptions();
};

