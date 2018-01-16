#pragma once
#include <windows.h>

enum MouseEvents
{
	LeftClick = WM_LBUTTONDOWN,
	LeftClickUp = WM_LBUTTONUP,
	DoubleLeftClick = WM_LBUTTONDBLCLK,
	RightClick = WM_RBUTTONDOWN,
	DoubleRightClick = WM_RBUTTONDBLCLK,
	MiddleClick = WM_MBUTTONDOWN
};
