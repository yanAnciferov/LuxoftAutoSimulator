#ifndef COM_COMPANY_MODULE_MYTYPES_H
#define COM_COMPANY_MODULE_MYTYPES_H

#include "MyTypes.h"

#endif
class ScoreTable {
	

public:

	ScoreTable();

	void setDistance(int distance);

	void setSpeed(int speed);

	void setTime(clock_t time);

	void updateSpeed();

	void updateDistance();

	void updateTimer();

private: 

	int speed_;
	clock_t time_;
	int distance_;

	
};