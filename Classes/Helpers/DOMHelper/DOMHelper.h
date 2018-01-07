#pragma once
#include <map>
#include <functional>
#include "../../CartesianPlane/CartesianPoint/CartesianPoint.h"

class DOMHelper
{
private:
	static std::map<std::string, bool> mouseSubscriptions;
	std::string SubscribeToMouseEvent();
	void ApplySubscription(std::string subscriptionId, std::function<void()> callback);
public:
	DOMHelper();
	bool IsSubscriptionActive(const std::string subscriptionId);
	std::string SubscribeOnClick(std::function<void()> callback);
	void Unsubscribe(std::string subscriptionId);
	CartesianPoint GetLeftMouseClick();
	bool IsValidMouseClick(CartesianPoint point);
};

