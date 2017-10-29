#pragma once
#include "Observer.h"
#include "Player.h"
#include "console.h"
#include "RoadBorder.h"


class Road : public ISubscriber
{


	RoadBorder* _border;
	
	void printStrip();

	int _strip;
	
public:

	void print();

	void move(int moveCount);

	int getWidthRoad();

	int getHiegthRoad();

	
	RoadBorder& getBorder();

	Road();

	~Road();


	virtual void handleEvent(IPublisher* publisher) override;

	// Inherited via ISubscriber
	virtual void addPublisher(IPublisher * publisher) override;
};

