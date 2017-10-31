#ifndef COM_COMPANY_MODULE_CAR_H
#define COM_COMPANY_MODULE_CAR_H

#include "Car.h"

#endif 


void Car::setColor(Color color) {
	color_ = color;
	isAngry_ = false;
}



Car::Car() {
	dx_ = 0.0;
	yPosition_ = START_Y_POSITION_FOR_BOT, xPosition_ = START_X_POSITION_FOR_BOT;
	speed_ = MIN_SPEED_FOR_BOOT;
	maxSpeed_ = MAX_CAR_SPEED;
	distance_ = 0;
	direction_ = DIRECTION_NORTH;
	color_ = COLOR_RED;
	isAngry_ = false;
}


Car::Car(const Car& car) {

	list<IPublisher*> publishers_;
	this->dx_ = car.dx_;
	this->yPosition_ = car.yPosition_, this->xPosition_ = car.xPosition_;
	this->speed_ = car.speed_;
	this->maxSpeed_ = car.maxSpeed_;
	this->distance_ = car.distance_;
	this->direction_ = this->direction_;
	this->collisionCar_ = shared_ptr<Collision>(new Collision(*collisionCar_));
	this->border_ = car.border_;
	this->color_ = car.color_;
	this->isAngry_ = car.isAngry_;
}

Car::Car(ICollisionFactory* factory) : collisionCar_(factory->createCollision(*this)) {
	dx_ = 0.0;
	yPosition_ = START_Y_POSITION_FOR_BOT, xPosition_ = START_X_POSITION_FOR_BOT;
	speed_ = MIN_SPEED_FOR_BOOT;
	maxSpeed_ = MAX_CAR_SPEED;
	distance_ = 0;
	direction_ = DIRECTION_NORTH;
	color_ = COLOR_RED;
	isAngry_ = false;
}

Car::Car(ICollisionFactory* factory,
	int startSpeed,
	int maxSpeed,
	int x, int y,
	shared_ptr<RoadBorder> border,
	Direction direction,
	Color color
)	: Car()
{
	xPosition_ = x;
	yPosition_ = y;
	speed_ = startSpeed;
	maxSpeed_ = maxSpeed;
	direction_ = direction;
	border_ = border;
	color_ = color;
	collisionCar_ = factory->createCollision(*this);

}

Car::Car(ICollisionFactory* factory,
	int startSpeed,
	int maxSpeed,
	int x, int y,
	shared_ptr<RoadBorder> border,
	Direction direction,
	Color color,
	bool isAngry
) : Car(factory,startSpeed,maxSpeed,x,y,border,direction,color)
{
	isAngry_ = isAngry;

}


void Car::accelerate() {
	if (speed_ != getMaxSpeed())
		speed_++;

}

void Car::slowDown() {
	if (speed_ != MIN_CAR_SPEED)
		speed_--;

}

int Car::getMaxSpeed() {
	return maxSpeed_;
}

Direction Car::getDirection() const {
	return direction_;
}

int Car::getCurrentSpeed() {
	return speed_;
}

int Car::getY() const {
	return yPosition_;
}

int Car::getX() const {
	return xPosition_;
}

void Car::draw() {
	
	for (int i = 0; i < collisionCar_->getLength(); i++)
	{
		int x = collisionCar_->at(i).X;
		int y = collisionCar_->at(i).Y;
		Console::SetColor(color_, COLOR_DARKGRAY);
		if (x <= border_->getDownBorder() && x >= border_->getUpBorder()) {
			Console::SetCursorPosition(y,x);
			cout << char(RECTANGLE_SYMBOL);
		}
	}
}

void Car::move(int moveCount) {
	clear();
	for (int i = 0; i < collisionCar_->getLength(); i++)
	{
		collisionCar_->at(i).X-=moveCount;
	}
	xPosition_ -= moveCount;
	draw();
	
	for each (auto var in publishers_)
	{
		var->notifySubscriber();
	}
}

void Car::clear() {

	
	for (int i = 0; i < collisionCar_->getLength(); i++)
	{
		int x = collisionCar_->at(i).X;
		int y = collisionCar_->at(i).Y;
		Console::SetColor(color_, COLOR_DARKGRAY);
		if (x <= border_->getDownBorder() && x >= border_->getUpBorder()) {
			Console::SetCursorPosition(y, x);
			cout << ' ';
		}
	}
}

void Car::turnLeft() {
	
	if (yPosition_ > border_->getLeftBorder() + 1 && speed_ > MIN_CAR_SPEED_FOR_TURN)
	{
		clear();
		for (int i = 0; i < collisionCar_->getLength(); i++)
		{
			collisionCar_->at(i).Y--;
		}
		yPosition_--;
		draw();
	}
	
	
}

void Car::turnRigth() {
	
	if (yPosition_ < border_->getRigthBorder() - 1 && speed_ > MIN_CAR_SPEED_FOR_TURN)
	{
		clear();
		for (int i = 0; i < collisionCar_->getLength(); i++)
		{
			collisionCar_->at(i).Y++;
		}
		yPosition_++;
		draw();
	}
	
}


Car::~Car() {
	
}

Color Car::getColor() const {
	return color_;
}

void Car::handleEvent(IPublisher * publisher)
{
	Player* player = dynamic_cast<Player*>(publisher);
	if (player != NULL)
	{
		double numberOfMovements = player->getDx();
		if(numberOfMovements >= 1){
			switch (direction_)
			{
			case DIRECTION_NORTH:
				dx_ -= numberOfMovements;
				break;
			case DIRECTION_SOUTH:
				dx_ += numberOfMovements;
				break;
			default:
				break;
			}

			if (isAngry_)
			{
				int rangeY = player->getY() - yPosition_;
				int rangeX = player->getX() - xPosition_;
				if (rangeX > 0 && rangeX < RANGE_ATAC_PLAYER || rangeX < 0 && rangeX > -RANGE_ATAC_PLAYER)
				{
					if (rangeY > 0 && rangeY < RANGE_ATAC_PLAYER)
					{
						turnRigth();
					}
					else if (rangeY < 0 && rangeY > -6) {
						turnLeft();
					}
				}
			}
		}

		

		shared_ptr<Collision> playerCollision = player->getCollision();

		if (collisionCar_->isCollision(playerCollision))
			throw AccidentExeption();

	}
	
}

shared_ptr<Collision> Car::getCollision() const
{
	return collisionCar_;
}

void Car::addPublisher(IPublisher * publisher)
{
	publishers_.push_back(publisher);
}

bool Car::update() {
	dx_ +=	static_cast<double>(getCurrentSpeed()) / MS_PER_FRAME;
	if (dx_ >= 1 || dx_ <= -1)
	{
		//move(_dx);
		switch (direction_)
		{
		case DIRECTION_NORTH:
			move(dx_);
			break;
		case DIRECTION_SOUTH:
			move(-1 * dx_);
			break;
		default:
			break;
		}
		dx_ -= static_cast<int>(dx_);
		if (xPosition_ > POSITION_FOR_REMOVE_BOT)
		{
			for each (auto var in publishers_)
			{
				var->removeSubscriber(this);
			}
			return false;
		}
	}
	return true;
}


