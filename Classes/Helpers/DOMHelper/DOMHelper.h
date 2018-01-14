#pragma once
#include <map>
#include <functional>
#include "MouseClick/MouseClickPoint.h"
#include "../../Enums/MouseEvents.h";

class DOMHelper
{
private:
	static std::map<std::string, bool> mouseSubscriptions;
	std::string GenerateSubscriptionId();
	void ApplySubscription(std::string subscriptionId, std::function<void()> callback, MouseEvents mouseEvent);
	std::string SubscribeOnMouseEvent(std::function<void()> callback, MouseEvents mouseEvent);
	MouseClickPoint GetMouseEvent(MouseEvents mouseEvent);
public:
	DOMHelper();
	bool IsSubscriptionActive(const std::string subscriptionId);
	void Unsubscribe(std::string subscriptionId);
	MouseClickPoint GetLeftMouseClick();
	MouseClickPoint GetRightMouseClick();
	std::string SubscribeOnLeftClick(std::function<void()> callback);
	std::string SubscribeOnRightClick(std::function<void()> callback);
};

