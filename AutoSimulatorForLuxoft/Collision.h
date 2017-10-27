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

	bool isCollision(const Collision& collision) {
		for (int i = 0; i < _coords.size(); i++)
		{
			for (int j = 0; j < collision._coords.size(); j++)
			{
				if (_coords[i].X == collision._coords[j].X
						&& _coords[i].Y == collision._coords[j].Y)
					return true;
			}
		}
		return false;
	}
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