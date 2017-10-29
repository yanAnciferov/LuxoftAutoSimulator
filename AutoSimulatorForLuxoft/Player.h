#pragma once
#include "Header.h"
#include "IUpdate.h"
#include "Observer.h"
#include "console.h"
#include "Car.h"
#include "Road.h"
#include "Collision.h"
class Car;
class Collision;
class Player : public IUpdate, public IPublisher
{
	double _dx = 0.0;
	int _distance = 0;
	vector<ISubscriber*> _subscribers;
	Car* _car;

	void move();

	



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
};

