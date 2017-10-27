#include "Collision.h"

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
	_coords = coords;
}

COORD& Collision::at(int index) {

	return _coords[index];
}

unsigned int Collision::getLength() {
	return _coords.size();
}