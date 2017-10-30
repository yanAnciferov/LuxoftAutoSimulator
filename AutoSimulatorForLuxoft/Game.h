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

public:
	Game();
	
	void start();

private:

	Road* road_;
	Player* player_;
	list<IUpdate*> gameObjects_;
	ScoreTable scoreTable_;
	Timer timer_;

	bool update();

	Car* CreateCar();

	ICollisionFactory* getRandCollisionFactory();

	bool userEvent();
	
};

