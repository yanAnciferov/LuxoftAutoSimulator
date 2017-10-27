#pragma once
//#include "ICarPrint.h"
#include "console.h"
#include "IUpdate.h"
#include "Observer.h"
#include "Player.h"
#include "RoadBorder.h"
#include "Collision.h"
class ICollisionFactory;
class Collision;

class accident_exeption : public exception {
public:
	virtual const char* what() const override {
		return "The end.";
	}
};

class Car : public IUpdate, public ISubscriber
{

	list<IPublisher*> _publishers;
	double _dx = 0.0;
	int _yPosition = 5, _xPosition = 26;
	int _speed = 10;
	int _maxSpeed = 140;
	int _distance = 0;
	Direction _direction = DIRECTION_NORTH;
	Collision* _collisionCar;
	RoadBorder _border;
	Color _color = COLOR_RED;
public:
	Car(ICollisionFactory* factory);

	Car(ICollisionFactory* factory,
		int startSpeed,
		int maxSpeed,
		int x, int y,
		const RoadBorder& border,
		Direction direction );
	
	RoadBorder& getBorder(){
		return _border;
	}

	Color getColor() { return _color; }
	void setColor(Color color) { _color = color; }

	void accelerate();

	void slowDown();

	virtual int getMaxSpeed();
	int getCurrentSpeed();

	int getY();

	int getX();

	void draw();

	void clear();

	void turnLeft();

	void turnRigth();

	void move(int moveCount);

	Direction getDirection();

	Collision* getCollision() {
		return _collisionCar;
	}

	~Car();


	// Inherited via IUpdate
	virtual bool update() override;


	// Inherited via ISubscriber
	virtual void handleEvent(IPublisher * publisher) override;


	// Inherited via ISubscriber
	virtual void addPublisher(IPublisher * publisher) override;

};

