#pragma once
#include "Header.h"
#include "IUpdate.h"
#include <list>
#include "Timer.h"
#include "console.h"
#include "Player.h"
#include "Road.h"
#include "ScoreTable.h"
#include "Collision.h"
using namespace std;
class Game
{
	Road* road;
	Player* player;
	list<IUpdate*> _gameObjects;
	ScoreTable _scoreTable;
	Timer timer;
public:
	Game() {
		_gameObjects.push_back(&timer);
		Console::SetCursorVisible(false);
	}
	
	void start() {
		Console::WindowFont();
		Console::SetColor(COLOR_GREEN, COLOR_GREEN);
		system("cls");
		Console::SetWindowSize(1200,1000);
		srand(time(0));
		road = new Road();
		road->print();
		_scoreTable = *new ScoreTable();
		player = new Player(new Car(new StandartCarCollisionFactory(), 0, 140, 26, 26, road->getBorder(), DIRECTION_NORTH));
		player->addSubscriber(road);
		player->draw();
		while (true)
		{
			
			float start = GetTickCount();
			
			if (!userEvent())
				return;

			if (!timer.isPause()) {
				if (!update())
					return;
			}
			else timer.update();
			int sleepValue = start + MS_PER_FRAME - GetTickCount();
			if (sleepValue >= 0)
			{
				Sleep(sleepValue);
			}
			
			
		}
	}

	bool update() {
		try
		{
			player->update();
			for each (IUpdate* var in _gameObjects)
			{
				if (!var->update()) {
					_gameObjects.remove(var);
					delete var;
					break;
				}

			}
			player->draw();
		}
		catch (exception& ex)
		{
			Console::SetColor(COLOR_WHITE, COLOR_GREEN);
			system("cls");
			Console::SetWindowSize(500, 500);
			Console::SetCursorPosition(10,10);
			cout << "Game over";
			Console::SetCursorPosition(10, 12);
			cout << "Distance: " << player->getDistance();
			Console::SetCursorPosition(10, 14);
			cout << "Time: " << (int)timer.getTime() ;
			while (_getch() != KEYS_ENTER) {}
			return false;
		}
		

		_scoreTable.setDistance(player->getDistance());
		_scoreTable.setTime(timer.getTime());
		_scoreTable.setSpeed(player->getCurrentSpeed());

		if (_gameObjects.size() < 6)
		{
			Car* car = CreateCar();
			_gameObjects.push_back(car);
			player->addSubscriber(car);
		}
		return true;
	}

	Car* CreateCar() {
		RoadBorder border = road->getBorder();
		int speed = 10 + rand() % 50;
		int maxSpeed = 140;
		Direction direction = (Direction)(rand() % 2);
		int x = -5;
		int y;
		if (direction == DIRECTION_NORTH)
		{
			y = border.rigthBorder / 2 + rand() % 17;
		}
		else {
			y = 2 + rand() % (border.rigthBorder / 2) - 6;
		}
		y -= y % 4;
		y += 5;
		if (y < 5)
		{
			y = 5;
		}

		return new Car(getRandCollisionFactory(), speed, maxSpeed, x, y, border, direction);
	}

	ICollisionFactory* getRandCollisionFactory() {
		switch (rand()%4)
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


	

	bool userEvent() {
		if (_kbhit())
		{
			
			char keyCode = _getch();

			if (timer.isPause() && keyCode != KEYS_ENTER)
				return true;

			switch (keyCode)
			{
			case KEYS_ENTER:
				timer.pause();
				break;
			case KEYS_UPKEY:
				player->accelerate();
				break;
			case KEYS_DOWNKEY:
				player->slowDown();
				break;
			case KEYS_LEFTKEY:
				player->turnLeft();
				break;
			case KEYS_RIGHTKEY:
				player->turnRigth();
				break;
			case KEYS_ESC:
				return false;

			default:
				break;
			}
		}
		return true;
	}
	
};

