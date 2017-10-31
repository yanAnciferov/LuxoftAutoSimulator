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

	Car(const Car& car);

	Car(ICollisionFactory* factory,
		int startSpeed,
		int maxSpeed,
		int x, int y,
		shared_ptr<RoadBorder> border,
		Direction direction,
		Color color);

	Car(ICollisionFactory* factory,
		int startSpeed,
		int maxSpeed,
		int x, int y,
		shared_ptr<RoadBorder> border,
		Direction direction,
		Color color,
		bool isAngry);
	
	Car();

	shared_ptr<RoadBorder> getBorder() const {
		return border_;
	}

	Color getColor() const;

	void setColor(Color color);

	void accelerate();

	void slowDown();

	virtual int getMaxSpeed();
	int getCurrentSpeed();

	int getY() const;

	int getX() const;

	void draw();

	void clear();

	void turnLeft();

	void turnRigth();

	void move(int moveCount);

	Direction getDirection() const;

	shared_ptr<Collision> getCollision() const;

	virtual ~Car();

	virtual bool update() override;

	virtual void handleEvent(IPublisher * publisher) override;

	virtual void addPublisher(IPublisher * publisher) override;


private:

	list<IPublisher*> publishers_;
	double dx_;
	int yPosition_, xPosition_ ;
	int speed_;
	int maxSpeed_;
	int distance_;
	Direction direction_;
	shared_ptr<Collision> collisionCar_;
	shared_ptr<RoadBorder> border_;
	Color color_ ;
	bool isAngry_;

};

