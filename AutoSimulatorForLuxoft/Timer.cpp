#pragma once
#include "Timer.h"

bool Timer::update() {
	if (_start == false)
	{
		_clock1 = clock();
		_start = true;
	}
	else
	{
		_clock2 = _clock1;
		_clock1 = clock();

		if (_pause == false)
			_timer += _clock1 - _clock2;

	}
	return true;
};

clock_t Timer::getTime() {
	return _timer / CLOCKS_PER_SEC;
}

void Timer::pause() {
	_pause = !_pause;
	Console::SetCursorPosition(47, 9);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	if (_pause)
	{
		cout << "Pause";
	}
	else {

		cout << "     ";
	}
}

bool Timer::isPause() {
	return _pause;
}

