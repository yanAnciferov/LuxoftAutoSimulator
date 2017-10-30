#pragma once
#include "Header.h"
#include "IUpdate.h"
#include "console.h"
class Timer: public IUpdate {

public:
	virtual bool update() override;

	clock_t getTime();

	void pause();

	bool isPause();

private:
	clock_t clock1_;
	clock_t clock2_;
	clock_t timer_;
	bool start_ = false;
	bool pause_ = false;
};