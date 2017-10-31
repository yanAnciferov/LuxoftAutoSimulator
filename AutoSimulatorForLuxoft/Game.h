#ifndef COM_COMPANY_MODULE_HEADER_H
#define COM_COMPANY_MODULE_HEADER_H

#include "Header.h"

#endif

#ifndef COM_COMPANY_MODULE_MYTYPES_H
#define COM_COMPANY_MODULE_MYTYPES_H

#include "MyTypes.h"

#endif



class Game
{

public:
	Game();
	
	void start();

	virtual ~Game() {};

protected:

	Road road_;
	Player player_;
	vector<IUpdate*> gameObjects_;
	ScoreTable scoreTable_;
	Timer timer_;

	virtual bool update() = 0;

	virtual Car* createCar();

	ICollisionFactory* getRandCollisionFactory();

	bool userEvent();

	void gameOver();

	void gameWinner();
	
};

class GameForAScore : public Game{

public:
	GameForAScore();

protected:
	virtual bool update() override;
};

class GameWithLavel : public Game {

public:
	GameWithLavel();

protected:
	virtual bool update() override;

	virtual Car* createCar() override;

private:
	vector<LvlInfo> lvls_;
	int currentLvl_;

	void nextLvl();
};

