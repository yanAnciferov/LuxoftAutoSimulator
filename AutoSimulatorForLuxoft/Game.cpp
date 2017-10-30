#include "Game.h"

Game::Game() {
	gameObjects_.push_back(&timer_);
	Console::SetCursorVisible(false);
}

void Game::start() {
	Console::WindowFont();
	Console::SetColor(COLOR_GREEN, COLOR_GREEN);
	system("cls");
	Console::SetWindowSize(1200, 1000);
	srand(time(0));
	road_ = new Road();
	road_->print();
	scoreTable_ = *new ScoreTable();
	player_ = new Player(
					new Car(
						new StandartCarCollisionFactory(),
						0,
						140,
						26,
						26,
						road_->getBorder(),
						DIRECTION_NORTH,
						COLOR_RED
					)
			);
	player_->addSubscriber(road_);
	player_->draw();
	while (true)
	{

		float start = GetTickCount();

		if (!userEvent())
			return;

		if (!timer_.isPause()) {
			if (!update())
				return;
		}
		else timer_.update();
		int sleepValue = start + MS_PER_FRAME - GetTickCount();
		if (sleepValue >= 0)
		{
			Sleep(sleepValue);
		}


	}
}

bool Game::update() {
	try
	{
		player_->update();
		for each (IUpdate* var in gameObjects_)
		{
			if (!var->update()) {
				gameObjects_.remove(var);
				delete var;
				break;
			}

		}
		player_->draw();
	}
	catch (exception& ex)
	{
		Console::SetColor(COLOR_WHITE, COLOR_GREEN);
		system("cls");
		Console::SetWindowSize(500, 500);
		Console::SetCursorPosition(10, 10);
		cout << "Game over";
		Console::SetCursorPosition(10, 12);
		cout << "Distance: " << player_->getDistance();
		Console::SetCursorPosition(10, 14);
		cout << "Time: " << static_cast<int>(timer_.getTime());
		while (_getch() != KEYS_ENTER) {}
		return false;
	}


	scoreTable_.setDistance(player_->getDistance());
	scoreTable_.setTime(timer_.getTime());
	scoreTable_.setSpeed(player_->getCurrentSpeed());

	if (gameObjects_.size() < 6)
	{
		Car* car = CreateCar();
		gameObjects_.push_back(car);
		player_->addSubscriber(car);
	}
	return true;
}

Car* Game::CreateCar() {
	RoadBorder border = road_->getBorder();
	int speed = 10 + rand() % 50;
	int maxSpeed = 140;
	Direction direction = static_cast<Direction>(rand() % 2);
	int x = -5;
	int y;
	if (direction == DIRECTION_NORTH)
	{
		y = border.getRigthBorder() / 2 + rand() % 17;
	}
	else {
		y = 2 + rand() % (border.getRigthBorder() / 2) - 6;
	}
	y -= y % 4;
	y += 5;
	if (y < 5)
	{
		y = 5;
	}
	Color _color = static_cast<Color>(rand() % 15);
	while (_color == COLOR_DARKGRAY) {
		_color = static_cast<Color>(rand() % 15);
	}
	return new Car(getRandCollisionFactory(), speed, maxSpeed, x, y, border, direction, _color);
}

ICollisionFactory* Game::getRandCollisionFactory() {
	switch (rand() % 4)
	{
	case 0:
		return new StandartCarCollisionFactory();
	case 1:
		return new HatchbackCarCollisionFactory();
	case 2:
		return new SmartCarCollisionFactory();
	case 3:
		return new SportCarCollisionFactory();
	default:
		break;
	}
}

bool Game::userEvent() {
	if (_kbhit())
	{

		char keyCode = _getch();

		if (timer_.isPause() && keyCode != KEYS_ENTER)
			return true;

		switch (keyCode)
		{
		case KEYS_ENTER:
			timer_.pause();
			break;
		case KEYS_UPKEY:
			player_->accelerate();
			break;
		case KEYS_DOWNKEY:
			player_->slowDown();
			break;
		case KEYS_LEFTKEY:
			player_->turnLeft();
			break;
		case KEYS_RIGHTKEY:
			player_->turnRigth();
			break;
		case KEYS_ESC:
			return false;

		default:
			break;
		}
	}
	return true;
}



