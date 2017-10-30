#ifndef COM_COMPANY_MODULE_PLAYER_H
#define COM_COMPANY_MODULE_PLAYER_H

#include "Player.h"

#endif 

Player::Player(Car* car) {
	car_ = car;
}

void Player::move() {
	notifySubscriber();
	distance_ += dx_;
}

int Player::getDistance() {
	return distance_;
}

void Player::accelerate() {
	car_->accelerate();
	
}

void Player::slowDown() {
	car_->slowDown();
	
}

int Player::getMaxSpeed() {
	return car_->getMaxSpeed();
}

int Player::getCurrentSpeed() {
	return car_->getCurrentSpeed();
}

int Player::getY() {
	return car_->getY();
}

int Player::getX() {
	return car_->getX();
}

double Player::getDx() {
	return dx_;
}

void Player::turnLeft() {
	car_->turnLeft();
}

void Player::turnRigth() {
	car_->turnRigth();
}

void Player::draw() {
	car_->draw();
}

void Player::clear() {
	car_->clear();
}

bool Player::update() {
	dx_ += static_cast<double>(getCurrentSpeed()) / MS_PER_FRAME;
	if (dx_ >= 1)
	{
		clear();
		move();
		dx_ -= static_cast<int>(dx_);

		draw();
	}
	return true;
};

Collision* Player::getCollision() {
	return car_->getCollision();
}

void Player::addSubscriber(ISubscriber * subscriber)  {
	subscribers_.push_back(subscriber);
	subscriber->addPublisher(this);
};

void Player::removeSubscriber(ISubscriber* subscriber) {
	
	for (size_t i = 0; i < subscribers_.size(); i++)
	{
		if (subscribers_[i] == subscriber) {
			subscribers_.erase(subscribers_.begin() + i);
			return;
		}
		
	}
		
}

void Player::notifySubscriber(){
	int size = subscribers_.size();
	
		for (int i = 0; i < size; i++)
		{
			subscribers_[i]->handleEvent(this);

		}
	
	
};

