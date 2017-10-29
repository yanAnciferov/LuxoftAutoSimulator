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
	Game();
	
	void start();

private:

	bool update();

	Car* CreateCar();

	ICollisionFactory* getRandCollisionFactory();

	bool userEvent();
	
};

