#ifndef COM_COMPANY_MODULE_TIMER_H
#define COM_COMPANY_MODULE_TIMER_H

#include "Timer.h"

#endif 

Timer::Timer() {
	start_ = false;
	pause_ = false;
	timer_ = 0;
	clock1_ = 0;
	clock2_ = 0;
}

bool Timer::update() {
	if (start_ == false)
	{
		clock1_ = clock();
		start_ = true;
	}
	else
	{
		clock2_ = clock1_;
		clock1_ = clock();

		if (pause_ == false)
			timer_ += clock1_ - clock2_;

	}
	return true;
};

clock_t Timer::getTime() {
	return timer_ / CLOCKS_PER_SEC;
}

void Timer::pause() {
	pause_ = !pause_;
	Console::SetCursorPosition(47, 9);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	if (pause_)
	{
		cout << "Pause";
	}
	else {

		cout << "     ";
	}
}

bool Timer::isPause() {
	return pause_;


}

void Timer::reset() {
	start_ = false;
	clock1_ = 0;
	clock2_ = 0;
	timer_ = 0;
}