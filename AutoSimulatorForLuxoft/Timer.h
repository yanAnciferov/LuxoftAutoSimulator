#pragma once
#include "Header.h"
#include "IUpdate.h"
#include "console.h"
class Timer: public IUpdate {


	clock_t _clock1;
	clock_t _clock2;
	clock_t _timer;
	bool _start = false;
	bool _pause = false;
public:
	virtual bool update() override;

	clock_t getTime();

	void pause();

	bool isPause();

};