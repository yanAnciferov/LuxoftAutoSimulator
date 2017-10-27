#pragma once
#include "Header.h"
#include "IUpdate.h"
#include "console.h"
class Timer: public IUpdate {


	clock_t _clock1;
	clock_t _clock2;
	clock_t timer;
	bool _start = false;
	bool _pause = false;
public:
	virtual bool update() override {
		if (!_start)
		{
			_clock1 = clock();
			_start = true;
		}
		else
		{
			_clock2 = _clock1;
			_clock1 = clock();

			if(!_pause)
				timer += _clock1 - _clock2;
			
		}
		return true;
	};

	clock_t getTime() {
		return timer / CLOCKS_PER_SEC;
	}

	void pause() {
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

	bool isPause() {
		return _pause;
	}

};