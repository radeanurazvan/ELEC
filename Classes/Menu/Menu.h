#pragma once
#include <vector>
#include "Models/MenuOption/MenuOption.h"

class Menu
{
private:
	static std::vector<MenuOption> Options;
	static void InitialiseFreeDrawOptions();
	static void DrawSquares();
public:
	Menu();
	static void Inititalise();

};

