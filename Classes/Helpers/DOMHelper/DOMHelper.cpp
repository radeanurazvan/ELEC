#include "DOMHelper.h"
#include "../../Guid/Guid.h"
#include "../../../graphics.h"
#include <thread>
#include "../GraphicsHelper/GraphicsHelper.h"
#include "MouseClick/MouseClickPoint.h"

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

std::string DOMHelper::SubscribeOnLeftClick(std::function<void()> callback)
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

MouseClickPoint DOMHelper::GetLeftMouseClick()
{
	int x, y;
	getmouseclick(WM_LBUTTONDOWN, x, y);
	if(x == -1 && y == -1)
	{
		return MouseClickPoint::InvalidClick();
	}

	auto click = MouseClickPoint(x, y);
	GraphicsHelper::DecomputeCoordinates(click.Point);
	return click;
}



