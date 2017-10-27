#pragma once

struct RoadBorder {
	RoadBorder(int left,
		int rigth,
		int down,
		int up) {
		leftBorder = left;
		rigthBorder = rigth;
		downBorder = down;
		upBorder = up;
	}
	RoadBorder() = default;
	int leftBorder = 0;
	int rigthBorder = 0;
	int downBorder = 0;
	int upBorder = 0;
};