#pragma once
#include "console.h"
#include "Header.h"
class ScoreTable {
	int _speed = 0;
	clock_t _time = 0;
	int _distance = 0;

	void updateSpeed();

	void updateDistance();

	void updateTimer();

public:

	ScoreTable();

	void setDistance(int distance);
	void setSpeed(int speed);

	void setTime(clock_t time);
};