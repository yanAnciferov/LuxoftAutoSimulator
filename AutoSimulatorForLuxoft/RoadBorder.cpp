#include "RoadBorder.h"

RoadBorder::RoadBorder(int left,
	int rigth,
	int down,
	int up) {
	_leftBorder = left;
	_rigthBorder = rigth;
	_downBorder = down;
	_upBorder = up;
}

RoadBorder::RoadBorder() {
	_leftBorder = 0;
	_rigthBorder = 0;
	_downBorder = 0;
	_upBorder = 0;
};

const int RoadBorder::getLeftBorder() {
	return _leftBorder;
}

const int RoadBorder::getRigthBorder() {
	return _rigthBorder;
}

const int RoadBorder::getDownBorder() {
	return _downBorder;
}

const int RoadBorder::getUpBorder() {
	return _upBorder;
}