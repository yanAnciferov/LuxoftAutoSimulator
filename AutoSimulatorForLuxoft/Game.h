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

private:

	Road road_;
	Player player_;
	vector<IUpdate*> gameObjects_;
	ScoreTable scoreTable_;
	Timer timer_;

	bool update();

	Car* createCar();

	ICollisionFactory* getRandCollisionFactory();

	bool userEvent();
	
};

