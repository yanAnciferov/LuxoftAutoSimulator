#include "Car.h"



Car::Car(ICollisionFactory* factory) {
	_collisionCar = &factory->createCollision(this);
}

Car::Car(ICollisionFactory* factory,
	int startSpeed,
	int maxSpeed,
	int x, int y,
	const RoadBorder& border,
	Direction direction
	)
{
	_xPosition = x;
	_yPosition = y;
	_speed = startSpeed;
	_maxSpeed = maxSpeed;
	_direction = direction;
	_border = border;
	_collisionCar = &factory->createCollision(this);
}


void Car::accelerate() {
	if (_speed != getMaxSpeed())
		_speed++;

}

void Car::slowDown() {
	if (_speed != 0)
		_speed--;

}

int Car::getMaxSpeed() {
	return _maxSpeed;
}

Direction Car::getDirection() {
	return _direction;
}

int Car::getCurrentSpeed() {
	return _speed;
}

int Car::getY() {
	return _yPosition;
}

int Car::getX() {
	return _xPosition;
}

void Car::draw() {
	
	for (int i = 0; i < _collisionCar->getLength(); i++)
	{
		int x = _collisionCar->at(i).X;
		int y = _collisionCar->at(i).Y;
		Console::SetColor(_color, COLOR_DARKGRAY);
		if (x <= _border.downBorder && x >= 0) {
			Console::SetCursorPosition(y,x);
			cout << char(219);
		}
	}
}

void Car::move(int moveCount) {
	clear();
	for (int i = 0; i < _collisionCar->getLength(); i++)
	{
		_collisionCar->at(i).X-=moveCount;
	}
	_xPosition -= moveCount;
	draw();
	
	for each (auto var in _publishers)
	{
		var->notifySubscriber();
	}
}

void Car::clear() {

	
	for (int i = 0; i < _collisionCar->getLength(); i++)
	{
		int x = _collisionCar->at(i).X;
		int y = _collisionCar->at(i).Y;
		Console::SetColor(_color, COLOR_DARKGRAY);
		if (x <= _border.downBorder && x >= 0) {
			Console::SetCursorPosition(y, x);
			cout << ' ';
		}
	}
}

void Car::turnLeft() {
	
	if (_yPosition > _border.leftBorder + 1 && _speed > 5)
	{
		clear();
		for (int i = 0; i < _collisionCar->getLength(); i++)
		{
			_collisionCar->at(i).Y--;
		}
		_yPosition--;
		draw();
	}
	
	
}

void Car::turnRigth() {
	
	if (_yPosition < _border.rigthBorder - 1 && _speed > 5)
	{
		clear();
		for (int i = 0; i < _collisionCar->getLength(); i++)
		{
			_collisionCar->at(i).Y++;
		}
		_yPosition++;
		draw();
	}
	
}


Car::~Car() {
	
}

void Car::handleEvent(IPublisher * publisher)
{
	Player* p = dynamic_cast<Player*>(publisher);
	if (p != NULL)
	{
		double moveCount = p->getDx();
		if(moveCount >= 1){
			switch (_direction)
			{
			case DIRECTION_NORTH:
				_dx -= moveCount;
				break;
			case DIRECTION_SOUTH:
				_dx += moveCount;
				break;
			default:
				break;
			}
		}
	}

	Collision& playerCollision = *p->getCollision();

	
	
		if (_collisionCar->isCollision(playerCollision))
			throw accident_exeption();
	
	
	
	
}

void Car::addPublisher(IPublisher * publisher)
{
	_publishers.push_back(publisher);
}

bool Car::update() {
	_dx += (double)getCurrentSpeed() / MS_PER_FRAME;
	if (_dx >= 1 || _dx <= -1)
	{
		//move(_dx);
		switch (_direction)
		{
		case DIRECTION_NORTH:
			move(_dx);
			break;
		case DIRECTION_SOUTH:
			move(-1 * _dx);
			break;
		default:
			break;
		}
		_dx -= (int)_dx;
		if (_xPosition > 60)
		{
			for each (auto var in _publishers)
			{
				var->removeSubscriber(this);
			}
			return false;
		}
	}
	return true;
}


