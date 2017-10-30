#pragma once
#include "Timer.h"

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

