#ifndef COM_COMPANY_MODULE_HEADER_H
#define COM_COMPANY_MODULE_HEADER_H

#include "Header.h"

#endif

#ifndef COM_COMPANY_MODULE_MYTYPES_H
#define COM_COMPANY_MODULE_MYTYPES_H

#include "MyTypes.h"

#endif

class Car;
class Collision;

class Player : public IUpdate, public IPublisher
{

public:
	Player(Car* car);

	void accelerate();

	void slowDown();

	int getMaxSpeed();

	int getCurrentSpeed();

	int getDistance();

	Collision* getCollision();

	int getY();
	int getX();

	double getDx();

	void turnLeft();

	void turnRigth();

	void draw();

	void clear();

	virtual bool update() override;

	virtual void addSubscriber(ISubscriber * subscriber) override;

	virtual void removeSubscriber(ISubscriber * subscriber) override;

	virtual void notifySubscriber() override;

private: 

	double dx_ = 0.0;
	int distance_ = 0;
	vector<ISubscriber*> subscribers_;
	Car* car_;

	void move();
};

