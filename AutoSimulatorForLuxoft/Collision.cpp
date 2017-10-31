#ifndef COM_COMPANY_MODULE_COLLISION_H
#define COM_COMPANY_MODULE_COLLISION_H

#include "Collision.h"

#endif 
shared_ptr<Collision> StandartCarCollisionFactory::createCollision(const Car& car) {
	short int x = car.getX(), y = car.getY();
	if (car.getDirection() == DIRECTION_NORTH)
	{
		vector<COORD> coords = {
			{ x,y },
			{ x + 1,y - 1 },{ x + 1,y },{ x + 1,y + 1 },
			{ x + 2,y },
			{ x + 3,y - 1 },{ x + 3,y + 1 }
		};

		return shared_ptr<Collision>(new Collision(coords));
	}
	else {
		vector<COORD> coords = {
			{ x,y },
			{ x - 1,y - 1 },{ x - 1,y },{ x - 1,y + 1 },
			{ x - 2,y },
			{ x - 3,y - 1 },{ x - 3,y + 1 }
		};

		return shared_ptr<Collision>(new Collision(coords));
	}

}

shared_ptr<Collision> HatchbackCarCollisionFactory::createCollision(const Car& car) {
	short int x = car.getX(), y = car.getY();
	if (car.getDirection() == DIRECTION_NORTH)
	{
		vector<COORD> coords = {
			{ x,y },
			{ x + 1,y - 1 },{ x + 1,y },{ x + 1,y + 1 },
			{ x + 2,y },
			{ x + 3,y - 1 },{ x + 3,y },{ x + 3,y + 1 }
		};

		return shared_ptr<Collision>(new Collision(coords));
	}
	else {
		vector<COORD> coords = {
			{ x,y },
			{ x - 1,y - 1 },{ x - 1,y },{ x - 1,y + 1 },
			{ x - 2,y },
			{ x - 3,y - 1 },{ x - 3,y },{ x - 3,y + 1 }
		};

		return shared_ptr<Collision>(new Collision(coords));
	}

}


shared_ptr<Collision> SmartCarCollisionFactory::createCollision(const Car& car) {
	short int x = car.getX(), y = car.getY();
	
		vector<COORD> coords = {
			{ x,y - 1 },{ x,y + 1 },
			{ x + 1,y },
			{ x + 2,y - 1 },{ x + 2,y + 1 }
		};

		return shared_ptr<Collision>(new Collision(coords));
}

shared_ptr<Collision> SportCarCollisionFactory::createCollision(const Car& car) {
	short int x = car.getX(), y = car.getY();

	if (car.getDirection() == DIRECTION_NORTH)
	{
		vector<COORD> coords = {
			{ x,y },
			{ x + 1,y + 1 },{ x + 1,y },{ x + 1,y - 1 },
			{ x + 2,y - 1 },{ x + 2,y + 1 }
		};
		return shared_ptr<Collision>(new Collision(coords));
	}
	else
	{
		vector<COORD> coords = {
			{ x- 2,y-1 },{ x-2,y + 1 },
			{ x - 1,y},{ x - 1,y - 1},{ x - 1,y + 1 },
			{ x ,y}
		};
		return shared_ptr<Collision>(new Collision(coords));
	}

	
}

Collision::Collision(const Collision& collision) {
	for (size_t i = 0; i <  collision.coords_.size(); i++)
	{
		this->coords_.push_back(COORD(*(collision.coords_.begin() + i)));
	}
	
}

Collision::Collision(vector<COORD>& coords) {
	vector<COORD> tmpCoords = coords;
	setCoords(tmpCoords);
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

bool Collision::isCollision(shared_ptr<Collision> collision) {
	for (int i = 0; i < coords_.size(); i++)
	{
		for (int j = 0; j < collision->coords_.size(); j++)
		{
			if (coords_[i].X == collision->coords_[j].X
				&& coords_[i].Y == collision->coords_[j].Y)
				return true;
		}
	}
	return false;
}