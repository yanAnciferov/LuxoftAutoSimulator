#ifndef COM_COMPANY_MODULE_HEADER_H
#define COM_COMPANY_MODULE_HEADER_H

#include "Header.h"

#endif



#ifndef COM_COMPANY_MODULE_CAR_H
#define COM_COMPANY_MODULE_CAR_H

#include "Car.h"

#endif 

class Car;

class Collision{

public:
	Collision() {};
	Collision(const Collision& collision);
	Collision(vector<COORD>& coords);
	void setCoords(vector<COORD>& coords);

	COORD& at(int index);

	unsigned int getLength();

	bool isCollision(shared_ptr<Collision> collision);

private: 
	vector<COORD> coords_;
};


struct ICollisionFactory {

public:
	virtual shared_ptr<Collision> createCollision(const Car& car) = 0;
	virtual ~ICollisionFactory() {};
};

class StandartCarCollisionFactory : public ICollisionFactory {

public:
	shared_ptr<Collision> createCollision(const Car& car) override;
};

class HatchbackCarCollisionFactory : public ICollisionFactory {

public:
	shared_ptr<Collision> createCollision(const Car& car) override;
};

class SmartCarCollisionFactory : public ICollisionFactory {

public:
	shared_ptr<Collision> createCollision(const Car& car) override;
};

class SportCarCollisionFactory : public ICollisionFactory {

public:
	shared_ptr<Collision> createCollision(const Car& car) override;
};