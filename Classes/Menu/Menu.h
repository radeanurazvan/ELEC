#pragma once
#include <vector>
#include "Models/MenuOption/MenuOption.h"

class Menu
{
private:
	Menu();
	static std::vector<MenuOption> Options;
	static void InitialiseFreeDrawOptions();
	static void DrawSquares();
public:
	static void Inititalise();

};

