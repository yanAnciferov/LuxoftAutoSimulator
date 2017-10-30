class IPublisher;

class ISubscriber
{
public:
	void virtual handleEvent(IPublisher* publisher) = 0;
	void virtual addPublisher(IPublisher* publisher) = 0;

	virtual ~ISubscriber() {}
};


class IPublisher
{
public:
	void virtual addSubscriber(ISubscriber* subscriber) = 0;
	void virtual removeSubscriber(ISubscriber* subscriber) = 0;
	void virtual notifySubscriber() = 0;

	virtual ~IPublisher() {}
};