#ifndef COM_COMPANY_MODULE_COLLISION_H
#define COM_COMPANY_MODULE_COLLISION_H

#include "Collision.h"

#endif 
Collision& StandartCarCollisionFactory::createCollision(Car* car) {
	short int x = car->getX(), y = car->getY();
	if (car->getDirection() == DIRECTION_NORTH)
	{
		vector<COORD> coords = {
			{ x,y },
			{ x + 1,y - 1 },{ x + 1,y },{ x + 1,y + 1 },
			{ x + 2,y },
			{ x + 3,y - 1 },{ x + 3,y + 1 }
		};

		return *new Collision(coords);
	}
	else {
		vector<COORD> coords = {
			{ x,y },
			{ x - 1,y - 1 },{ x - 1,y },{ x - 1,y + 1 },
			{ x - 2,y },
			{ x - 3,y - 1 },{ x - 3,y + 1 }
		};

		return *new Collision(coords);
	}

}

Collision& HatchbackCarCollisionFactory::createCollision(Car* car) {
	short int x = car->getX(), y = car->getY();
	if (car->getDirection() == DIRECTION_NORTH)
	{
		vector<COORD> coords = {
			{ x,y },
			{ x + 1,y - 1 },{ x + 1,y },{ x + 1,y + 1 },
			{ x + 2,y },
			{ x + 3,y - 1 },{ x + 3,y },{ x + 3,y + 1 }
		};

		return *new Collision(coords);
	}
	else {
		vector<COORD> coords = {
			{ x,y },
			{ x - 1,y - 1 },{ x - 1,y },{ x - 1,y + 1 },
			{ x - 2,y },
			{ x - 3,y - 1 },{ x - 3,y },{ x - 3,y + 1 }
		};

		return *new Collision(coords);
	}

}


Collision& SmartCarCollisionFactory::createCollision(Car* car) {
	short int x = car->getX(), y = car->getY();
	
		vector<COORD> coords = {
			{ x,y - 1 },{ x,y + 1 },
			{ x + 1,y },
			{ x + 2,y - 1 },{ x + 2,y + 1 }
		};

		return *new Collision(coords);
}

Collision& SportCarCollisionFactory::createCollision(Car* car) {
	short int x = car->getX(), y = car->getY();

	if (car->getDirection() == DIRECTION_NORTH)
	{
		vector<COORD> coords = {
			{ x,y },
			{ x + 1,y + 1 },{ x + 1,y },{ x + 1,y - 1 },
			{ x + 2,y - 1 },{ x + 2,y + 1 }
		};
		return *new Collision(coords);
	}
	else
	{
		vector<COORD> coords = {
			{ x- 2,y-1 },{ x-2,y + 1 },
			{ x - 1,y},{ x - 1,y - 1},{ x - 1,y + 1 },
			{ x ,y}
		};
		return *new Collision(coords);
	}

	
}

Collision::Collision(vector<COORD>& coords) {
	setCoords(coords);
}

void Collision::setCoords(vector<COORD>& coords) {
	coords_ = coords;
}

COORD& Collision::at(int index) {

	return coords_[index];
}

unsigned int Collision::getLength() {
	return coords_.size();
}

bool Collision::isCollision(const Collision& collision) {
	for (int i = 0; i < coords_.size(); i++)
	{
		for (int j = 0; j < collision.coords_.size(); j++)
		{
			if (coords_[i].X == collision.coords_[j].X
				&& coords_[i].Y == collision.coords_[j].Y)
				return true;
		}
	}
	return false;
}