#include "Player.h"
Player::Player(Car* car) {
	_car = car;
}


void Player::accelerate() {
	_car->accelerate();
	
}

void Player::slowDown() {
	_car->slowDown();
	
}

int Player::getMaxSpeed() {
	return _car->getMaxSpeed();
}

int Player::getCurrentSpeed() {
	return _car->getCurrentSpeed();
}

int Player::getY() {
	return _car->getY();
}

int Player::getX() {
	return _car->getX();
}

double Player::getDx() {
	return _dx;
}

void Player::turnLeft() {
	_car->turnLeft();
}

void Player::turnRigth() {
	_car->turnRigth();
}

void Player::draw() {
	_car->draw();
}

void Player::clear() {
	_car->clear();
}

bool Player::update() {
	_dx += (double)getCurrentSpeed() / MS_PER_FRAME;
	if (_dx >= 1)
	{
		clear();
		move();
		_dx -= (int)_dx;

		draw();
	}
	return true;
};

Collision* Player::getCollision() {
	return _car->getCollision();
}

void Player::addSubscriber(ISubscriber * subscriber)  {
	_subscribers.push_back(subscriber);
	subscriber->addPublisher(this);
};

void Player::removeSubscriber(ISubscriber* subscriber) {
	
	for (size_t i = 0; i < _subscribers.size(); i++)
	{
		if (_subscribers[i] == subscriber) {
			_subscribers.erase(_subscribers.begin() + i);
			return;
		}
		
	}
		
}

void Player::notifySubscriber(){
	int size = _subscribers.size();
	
		for (int i = 0; i < size; i++)
		{
			_subscribers[i]->handleEvent(this);

		}
	
	
};

