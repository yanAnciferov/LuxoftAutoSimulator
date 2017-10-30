#pragma once
#include "ScoreTable.h"

void  ScoreTable::updateSpeed()
{
	Console::SetCursorPosition(47, 3);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	cout << "Speed: " << speed_ << "   ";
}

void ScoreTable::updateDistance()
{
	Console::SetCursorPosition(47, 5);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	cout << "Distance: " << distance_ << "   ";
}

void ScoreTable::updateTimer()
{
	Console::SetCursorPosition(47, 7);
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	cout << "Time: " << static_cast<int>(time_) << endl;
}

ScoreTable::ScoreTable() {
	updateTimer();
	updateSpeed();
	updateDistance();
}

void ScoreTable::setDistance(int distance) {
	if (distance != distance_) {
		distance_ = distance;
		updateDistance();
	}

}

void ScoreTable::setSpeed(int speed) {
	if (speed != speed_) {
		speed_ = speed;
		updateSpeed();
	}

}

void ScoreTable::setTime(clock_t time) {
	if (time_ != time) {
		time_ = time;
		updateTimer();
	}


}
