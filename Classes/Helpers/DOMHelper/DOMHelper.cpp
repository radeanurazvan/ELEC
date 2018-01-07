#include "DOMHelper.h"
#include "../../Guid/Guid.h"
#include "../../../graphics.h"
#include <thread>
#include "../GraphicsHelper/GraphicsHelper.h"

std::map<std::string, bool> DOMHelper::mouseSubscriptions;
DOMHelper::DOMHelper()
{
}

std::string DOMHelper::SubscribeToMouseEvent()
{
	auto subscriptionId = Guid::NewGuid();
	mouseSubscriptions[subscriptionId] = true;
	return subscriptionId;
}

void DOMHelper::ApplySubscription(std::string subscriptionId , std::function<void()> callback)
{
	while (IsSubscriptionActive(subscriptionId))
	{
		callback();
	}
}

bool DOMHelper::IsSubscriptionActive(const std::string subscriptionId)
{
	return mouseSubscriptions[subscriptionId];
}

std::string DOMHelper::SubscribeOnClick(std::function<void()> callback)
{
	const auto subscriptionId = SubscribeToMouseEvent();
	std::thread subscriptionThread(&DOMHelper::ApplySubscription, this, subscriptionId, callback);
	subscriptionThread.detach();
	return subscriptionId;
}

void DOMHelper::Unsubscribe(std::string subscriptionId)
{
	mouseSubscriptions[subscriptionId] = false;
}

CartesianPoint DOMHelper::GetLeftMouseClick()
{
	int x, y;
	getmouseclick(WM_LBUTTONDOWN, x, y);
	auto point = CartesianPoint(x, y);
	if(point.GetX() != -1 && point.GetY() != -1)
	{
		GraphicsHelper::DecomputeCoordinates(point);
	}
	return point;
}

bool DOMHelper::IsValidMouseClick(CartesianPoint point)
{
	return point.GetX() != -1 && point.GetY() != -1;
}



