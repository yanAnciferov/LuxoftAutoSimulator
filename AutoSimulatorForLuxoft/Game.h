#pragma once
#include "Header.h"
#include "IUpdate.h"
#include "Timer.h"
#include "console.h"
#include "Player.h"
#include "Road.h"
#include "ScoreTable.h"
#include "Collision.h"
using namespace std;
class Game
{
	Road* _road;
	Player* _player;
	list<IUpdate*> _gameObjects;
	ScoreTable _scoreTable;
	Timer _timer;
public:
	Game() {
		_gameObjects.push_back(&_timer);
		Console::SetCursorVisible(false);
	}
	
	void start() {
		Console::WindowFont();
		Console::SetColor(COLOR_GREEN, COLOR_GREEN);
		system("cls");
		Console::SetWindowSize(1200,1000);
		srand(time(0));
		_road = new Road();
		_road->print();
		_scoreTable = *new ScoreTable();
		_player = new Player(new Car(new StandartCarCollisionFactory(), 0, 140, 26, 26, _road->getBorder(), DIRECTION_NORTH, COLOR_RED));
		_player->addSubscriber(_road);
		_player->draw();
		while (true)
		{
			
			float start = GetTickCount();
			
			if (!userEvent())
				return;

			if (!_timer.isPause()) {
				if (!update())
					return;
			}
			else _timer.update();
			int sleepValue = start + MS_PER_FRAME - GetTickCount();
			if (sleepValue >= 0)
			{
				Sleep(sleepValue);
			}
			
			
		}
	}

private:

	bool update() {
		try
		{
			_player->update();
			for each (IUpdate* var in _gameObjects)
			{
				if (!var->update()) {
					_gameObjects.remove(var);
					delete var;
					break;
				}

			}
			_player->draw();
		}
		catch (exception& ex)
		{
			Console::SetColor(COLOR_WHITE, COLOR_GREEN);
			system("cls");
			Console::SetWindowSize(500, 500);
			Console::SetCursorPosition(10,10);
			cout << "Game over";
			Console::SetCursorPosition(10, 12);
			cout << "Distance: " << _player->getDistance();
			Console::SetCursorPosition(10, 14);
			cout << "Time: " << (int)_timer.getTime() ;
			while (_getch() != KEYS_ENTER) {}
			return false;
		}
		

		_scoreTable.setDistance(_player->getDistance());
		_scoreTable.setTime(_timer.getTime());
		_scoreTable.setSpeed(_player->getCurrentSpeed());

		if (_gameObjects.size() < 6)
		{
			Car* car = CreateCar();
			_gameObjects.push_back(car);
			_player->addSubscriber(car);
		}
		return true;
	}

	Car* CreateCar() {
		RoadBorder border = _road->getBorder();
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
		Color _color = (Color)(rand() % 15);
		while (_color == COLOR_DARKGRAY){
			_color = (Color)(rand() % 15);
		}
		return new Car(getRandCollisionFactory(), speed, maxSpeed, x, y, border, direction, _color);
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

			if (_timer.isPause() && keyCode != KEYS_ENTER)
				return true;

			switch (keyCode)
			{
			case KEYS_ENTER:
				_timer.pause();
				break;
			case KEYS_UPKEY:
				_player->accelerate();
				break;
			case KEYS_DOWNKEY:
				_player->slowDown();
				break;
			case KEYS_LEFTKEY:
				_player->turnLeft();
				break;
			case KEYS_RIGHTKEY:
				_player->turnRigth();
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

