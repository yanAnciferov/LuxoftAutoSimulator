#pragma once


class RoadBorder {

public:

	RoadBorder(int left,
		int rigth,
		int down,
		int up);

	RoadBorder();

	const int getLeftBorder();

	const int getRigthBorder();

	const int getDownBorder();

	const int getUpBorder();
	
private:
	int _leftBorder;
	int _rigthBorder;
	int _downBorder;
	int _upBorder;
};