#include "Game.h"

Game::Game(): player_(
	new Car(
		new StandartCarCollisionFactory(),
		MIN_CAR_SPEED,
		MAX_CAR_SPEED,
		PLAYER_SPOWN_X,
		PLAYER_SPOWN_Y,
		road_.getBorder(),
		DIRECTION_NORTH,
		COLOR_RED
	)
) {


}

void Game::start() {
	
	srand(time(0));
	road_.print();
	scoreTable_ = *new ScoreTable();
	player_.addSubscriber(&road_);
	player_.draw();
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
		if (sleepValue >= MIN_SLEEP_VALUE)
		{
			Sleep(sleepValue);
		}


	}
}



void Game::gameOver() {
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	system("cls");
	Console::SetWindowSize(GAMEOVER_WINDOW_WIDTH, GAMEOVER_WINDOW_HEIGTH);
	Console::SetCursorPosition(10, 10);
	cout << "Game over";
	Console::SetCursorPosition(10, 12);
	cout << "Distance: " << player_.getDistance();
	Console::SetCursorPosition(10, 14);
	cout << "Time: " << static_cast<int>(timer_.getTime());
	while (_getch() != KEYS_ENTER) {}
}

void Game::gameWinner() {
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	system("cls");
	Console::SetWindowSize(GAMEOVER_WINDOW_WIDTH, GAMEOVER_WINDOW_HEIGTH);
	Console::SetCursorPosition(10, 10);
	cout << "You Win!!";
	while (_getch() != KEYS_ENTER) {}
	exit(0);
}

Car* Game::createCar() {

	shared_ptr<RoadBorder> border = road_.getBorder();

	int speed = MIN_SPEED_FOR_BOOT + rand() % MAX_SPEED_FOR_BOOT - MIN_SPEED_FOR_BOOT;
	int maxSpeed = MAX_CAR_SPEED;

	Direction direction = static_cast<Direction>(rand() % 2);

	int x = START_X_POSITION_FOR_BOT;
	int y;

	if (direction == DIRECTION_NORTH)
	{
		int spawnWidth = ((border->getRigthBorder() - border->getLeftBorder()) / 2) - border->getLeftBorder();
		y = border->getRigthBorder() / road_.getRoadwayCount() + rand() % spawnWidth;
	}
	else y = 2 + rand() % (border->getRigthBorder() / road_.getRoadwayCount()) - WIDTH_ROAD_COLUMN;
	

	y -= y % WIDTH_ROAD_COLUMN;
	y += WIDTH_ROAD_COLUMN;

	if (y < WIDTH_ROAD_COLUMN)
	{
		y = WIDTH_ROAD_COLUMN;
	}

	Color _color = static_cast<Color>(rand() % MAX_COLOR);

	while (_color == COLOR_DARKGRAY) {
		_color = static_cast<Color>(rand() % MAX_COLOR);
	}

	return new Car(getRandCollisionFactory(), speed, maxSpeed, x, y, border, direction, _color);
}

ICollisionFactory* Game::getRandCollisionFactory() {
	switch (static_cast<CaseCollisionFactory>(rand() % FACTORY_COUNT))
	{
	case FACTORY_STANDART:
		return new StandartCarCollisionFactory();
	case FACTORY_HATCHBACK:
		return new HatchbackCarCollisionFactory();
	case FACTORY_SMART:
		return new SmartCarCollisionFactory();
	case FACTORY_SPORT:
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
			player_.accelerate();
			break;
		case KEYS_DOWNKEY:
			player_.slowDown();
			break;
		case KEYS_LEFTKEY:
			player_.turnLeft();
			break;
		case KEYS_RIGHTKEY:
			player_.turnRigth();
			break;
		case KEYS_ESC:
			gameOver();
			return false;

		default:
			break;
		}
	}
	return true;
}

GameForAScore::GameForAScore() : Game() {}

bool GameForAScore::update() {
	try
	{
		player_.update();
		timer_.update();
		int tempSize = gameObjects_.size();
		for (int i = 0; i != tempSize; ++i)
		{

			if (gameObjects_[i]->update() == false) {
				delete gameObjects_[i];
				gameObjects_.erase(gameObjects_.begin() + i);

				i--;
				tempSize--;
			}
		}

		player_.draw();
	}
	catch (exception& ex)
	{
		gameOver();
		return false;
	}


	scoreTable_.setDistance(player_.getDistance());
	scoreTable_.setTime(timer_.getTime());
	scoreTable_.setSpeed(player_.getCurrentSpeed());

	if (gameObjects_.size() < MAX_GAME_OBJECT)
	{
		Car* car = createCar();
		gameObjects_.push_back(car);
		player_.addSubscriber(car);
	}
	return true;
}


GameWithLavel::GameWithLavel() : Game() {
	lvls_.push_back(LvlInfo(DifficultyMode::DIFFICALTY_EASY));
	lvls_.push_back(LvlInfo(DifficultyMode::DIFFICALTY_NORMAL));
	lvls_.push_back(LvlInfo(DifficultyMode::DIFFICALTY_HARD));
	currentLvl_ = -1;
	nextLvl();
}

bool GameWithLavel::update() {
	try
	{
		player_.update();
		timer_.update();
		int tempSize = gameObjects_.size();
		for (int i = 0; i != tempSize; ++i)
		{

			if (gameObjects_[i]->update() == false) {
				delete gameObjects_[i];
				gameObjects_.erase(gameObjects_.begin() + i);

				i--;
				tempSize--;
			}
		}

		player_.draw();
	}
	catch (exception& ex)
	{
		gameOver();
		return false;
	}


	scoreTable_.setDistance(player_.getDistance());
	scoreTable_.setTime(timer_.getTime());
	scoreTable_.setSpeed(player_.getCurrentSpeed());

	if (gameObjects_.size() < lvls_[currentLvl_].getCountEnemy())
	{
		Car* car = createCar();
		gameObjects_.push_back(car);
		player_.addSubscriber(car);
	}
	if (player_.getDistance() >= lvls_[currentLvl_].getDistanceForWin()) {
		nextLvl();
		if (lvls_.size() == currentLvl_)
		{
			gameWinner();
		}
	}



	return true;
}

Car* GameWithLavel::createCar() {

	shared_ptr<RoadBorder> border = road_.getBorder();

	int minSpeed = lvls_[currentLvl_].getMinSpeedCar();
	int maxSpeed = lvls_[currentLvl_].getMaxSpeedCar();
	int speed = minSpeed + rand() % maxSpeed - minSpeed;

	Direction direction = static_cast<Direction>(rand() % 2);

	int x = START_X_POSITION_FOR_BOT;
	int y;

	if (direction == DIRECTION_NORTH)
	{
		int spawnWidth = ((border->getRigthBorder() - border->getLeftBorder()) / 2) - border->getLeftBorder();
		y = border->getRigthBorder() / road_.getRoadwayCount() + rand() % spawnWidth;
	}
	else y = 2 + rand() % (border->getRigthBorder() / road_.getRoadwayCount()) - WIDTH_ROAD_COLUMN;


	y -= y % WIDTH_ROAD_COLUMN;
	y += WIDTH_ROAD_COLUMN;

	if (y < WIDTH_ROAD_COLUMN)
	{
		y = WIDTH_ROAD_COLUMN;
	}

	Color _color = static_cast<Color>(rand() % MAX_COLOR);

	while (_color == COLOR_DARKGRAY) {
		_color = static_cast<Color>(rand() % MAX_COLOR);
	}

	return new Car(
		getRandCollisionFactory(),
		speed, maxSpeed,
		x, y,
		border,
		direction,
		_color,
		lvls_[currentLvl_].getIsAngry()
	);
}

void GameWithLavel::nextLvl() {

	player_.reset();
	gameObjects_.clear();
	timer_.reset();
	

	currentLvl_++;

	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	system("cls");
	Console::SetCursorPosition(30, 30);
	cout << "Lvl " << currentLvl_;

	

	while (_getch() != KEYS_ENTER) {}

	player_.addSubscriber(&road_);
	road_.print();
	scoreTable_.updateSpeed();
}