#pragma once
#include "console.h"
#include "Header.h"
class ScoreTable {
	int _speed = 0;
	clock_t _time = 0;
	int _distance = 0;

	void updateSpeed()
	{
		Console::SetCursorPosition(47, 3);
		Console::SetColor(COLOR_WHITE, COLOR_GREEN);
		cout << "Speed: " << _speed << "   ";
	}

	void updateDistance()
	{
		Console::SetCursorPosition(47, 5);
		Console::SetColor(COLOR_WHITE, COLOR_GREEN);
		cout << "Distance: " << _distance << "   ";
	}

	void updateTimer()
	{
		Console::SetCursorPosition(47, 7);
		Console::SetColor(COLOR_WHITE, COLOR_GREEN);
		cout << "Time: " << (int)(_time) << endl;
	}

public:

	ScoreTable() {
		updateTimer();
		updateSpeed();
		updateDistance();
	}

	void setDistance(int distance) {
		if (distance != _distance) {
			_distance = distance;
			updateDistance();
		}
		
	}

	void setSpeed(int speed) {
		if (speed != _speed) {
			_speed = speed;
			updateSpeed();
		}
		
	}

	void setTime(clock_t time) {
		if (_time != time) {
			_time = time;
			updateTimer();
		}
		
		
	}
};