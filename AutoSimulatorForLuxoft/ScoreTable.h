#pragma once
#include "console.h"
#include "Header.h"
class ScoreTable {
	

public:

	ScoreTable();

	void setDistance(int distance);

	void setSpeed(int speed);

	void setTime(clock_t time);

private: 

	int speed_ = 0;
	clock_t time_ = 0;
	int distance_ = 0;

	void updateSpeed();

	void updateDistance();

	void updateTimer();
};