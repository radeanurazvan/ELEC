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

std::string DOMHelper::GenerateSubscriptionId()
{
	auto subscriptionId = Guid::NewGuid();
	mouseSubscriptions[subscriptionId] = true;
	return subscriptionId;
}

void DOMHelper::ApplySubscription(std::string subscriptionId , std::function<void()> callback, MouseEvents mouseEvent)
{
	while (IsSubscriptionActive(subscriptionId))
	{
		if(ismouseclick(mouseEvent))
		{
			callback();
		}
	}
}

std::string DOMHelper::SubscribeOnMouseEvent(std::function<void()> callback, MouseEvents mouseEvent)
{
	const auto subscriptionId = GenerateSubscriptionId();
	std::thread subscriptionThread(&DOMHelper::ApplySubscription, this, subscriptionId, callback, mouseEvent);
	subscriptionThread.detach();
	return subscriptionId;
}

MouseClickPoint DOMHelper::GetMouseEvent(MouseEvents mouseEvent)
{
	int x, y;
	getmouseclick(mouseEvent, x, y);
	if (x == -1 && y == -1)
	{
		return MouseClickPoint::InvalidClick();
	}

	auto click = MouseClickPoint(x, y);
	GraphicsHelper::DecomputeCoordinates(click.Point);
	return click;
}

bool DOMHelper::IsSubscriptionActive(const std::string subscriptionId)
{
	return mouseSubscriptions[subscriptionId];
}

std::string DOMHelper::SubscribeOnLeftClick(std::function<void()> callback)
{
	return SubscribeOnMouseEvent(callback, LeftClick);
}

std::string DOMHelper::SubscribeOnRightClick(std::function<void()> callback)
{
	return SubscribeOnMouseEvent(callback, RightClick);
}

void DOMHelper::Unsubscribe(std::string subscriptionId)
{
	mouseSubscriptions[subscriptionId] = false;
}

MouseClickPoint DOMHelper::GetLeftMouseClick()
{
	return GetMouseEvent(LeftClick);
}

MouseClickPoint DOMHelper::GetRightMouseClick()
{
	return GetMouseEvent(RightClick);
}



