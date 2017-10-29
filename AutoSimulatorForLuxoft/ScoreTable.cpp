#pragma once
#include "ScoreTable.h"

void  ScoreTable::updateSpeed()
{
	Console::SetCursorPosition(47, 3);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	cout << "Speed: " << _speed << "   ";
}

void ScoreTable::updateDistance()
{
	Console::SetCursorPosition(47, 5);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	cout << "Distance: " << _distance << "   ";
}

void ScoreTable::updateTimer()
{
	Console::SetCursorPosition(47, 7);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	cout << "Time: " << static_cast<int>(_time) << endl;
}

ScoreTable::ScoreTable() {
	updateTimer();
	updateSpeed();
	updateDistance();
}

void ScoreTable::setDistance(int distance) {
	if (distance != _distance) {
		_distance = distance;
		updateDistance();
	}

}

void ScoreTable::setSpeed(int speed) {
	if (speed != _speed) {
		_speed = speed;
		updateSpeed();
	}

}

void ScoreTable::setTime(clock_t time) {
	if (_time != time) {
		_time = time;
		updateTimer();
	}


}
