#ifndef COM_COMPANY_MODULE_HEADER_H
#define COM_COMPANY_MODULE_HEADER_H

#include "Header.h"

#endif

#ifndef COM_COMPANY_MODULE_OBSERVER_H
#define COM_COMPANY_MODULE_OBSERVER_H

#include "Observer.h"

#endif 

#ifndef COM_COMPANY_MODULE_ROADBORDER_H
#define COM_COMPANY_MODULE_ROADBORDER_H

#include "RoadBorder.h"

#endif 

#ifndef COM_COMPANY_MODULE_MYTYPES_H
#define COM_COMPANY_MODULE_MYTYPES_H

#include "MyTypes.h"

#endif

class ICollisionFactory;
class Collision;
class IUpdate;

class AccidentExeption : public exception {
public:
	virtual const char* what() const override {
		return "The end.";
	}
};

class Car : public IUpdate, public ISubscriber
{

public:
	Car(ICollisionFactory* factory);

	Car(ICollisionFactory* factory,
		int startSpeed,
		int maxSpeed,
		int x, int y,
		const RoadBorder& border,
		Direction direction,
		Color color);
	
	RoadBorder& getBorder(){
		return border_;
	}

	Color getColor() { return color_; }
	void setColor(Color color) { color_ = color; }

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

	Collision* getCollision();

	virtual ~Car();


	// Inherited via IUpdate
	virtual bool update() override;


	// Inherited via ISubscriber
	virtual void handleEvent(IPublisher * publisher) override;


	// Inherited via ISubscriber
	virtual void addPublisher(IPublisher * publisher) override;


private:

	list<IPublisher*> publishers_;
	double dx_ = 0.0;
	int yPosition_ = 5, xPosition_ = 26;
	int speed_ = 10;
	int maxSpeed_ = 140;
	int distance_ = 0;
	Direction direction_ = DIRECTION_NORTH;
	Collision* collisionCar_;
	RoadBorder border_;
	Color color_ = COLOR_RED;

};

