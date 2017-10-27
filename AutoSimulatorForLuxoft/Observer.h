#pragma once

struct IPublisher;

struct ISubscriber
{
	void virtual handleEvent(IPublisher* publisher) = 0;
	void virtual addPublisher(IPublisher* publisher) = 0;
};


struct IPublisher
{
	void virtual addSubscriber(ISubscriber* subscriber) = 0;
	void virtual removeSubscriber(ISubscriber* subscriber) = 0;
	void virtual notifySubscriber() = 0;
};