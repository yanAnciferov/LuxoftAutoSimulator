#pragma once
#include "Header.h"
#include "Car.h"
class Car;

class Collision{
	vector<COORD> _coords;

public:
	Collision() {};
	Collision(vector<COORD>& coords);
	void setCoords(vector<COORD>& coords);

	COORD& at(int index);

	unsigned int getLength();

	bool isCollision(const Collision& collision);
};


struct ICollisionFactory {

	virtual Collision& createCollision(Car* car) = 0;
};

class StandartCarCollisionFactory : public ICollisionFactory {

public:
	Collision& createCollision(Car* car) override;
};

class HatchbackCarCollisionFactory : public ICollisionFactory {

public:
	Collision& createCollision(Car* car) override;
};

class SmartCarCollisionFactory : public ICollisionFactory {

public:
	Collision& createCollision(Car* car) override;
};

class SportCarCollisionFactory : public ICollisionFactory {

public:
	Collision& createCollision(Car* car) override;
};