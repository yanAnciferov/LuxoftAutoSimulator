#pragma once
#ifndef COM_COMPANY_MODULE_OBSERVER_H
#define COM_COMPANY_MODULE_OBSERVER_H
#include "Observer.h"
#endif
#include "Player.h"

#include "RoadBorder.h"


class Road : public ISubscriber
{


public:

	void print();

	void move(int moveCount);

	int getWidthRoad();

	int getHiegthRoad();

	RoadBorder& getBorder();

	Road();

	~Road();

	virtual void handleEvent(IPublisher* publisher) override;

	virtual void addPublisher(IPublisher * publisher) override;

private:
	RoadBorder* border_;
	int strip_;

	void printStrip();

};

