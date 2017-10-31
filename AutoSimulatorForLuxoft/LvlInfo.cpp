#include "LvlInfo.h"

int LvlInfo::getCountEnemy() const {
	return countEnemyCar_;
}
int LvlInfo::getMaxSpeedCar() const {
	return maxSpeedCar_;
}
int LvlInfo::getMinSpeedCar() const {
	return minSpeedCar_;
}
bool LvlInfo::getIsAngry() const {
	return isAngry_;
}
int LvlInfo::getDistanceForWin() const {
	return distanceForWin_;
}

LvlInfo::LvlInfo(
	int countEnemyCar,
	int maxSpeedCar,
	int minSpeedCar,
	bool isAngry,
	int distanceForWin
) {
	countEnemyCar_ = countEnemyCar;
	maxSpeedCar_ = maxSpeedCar;
	minSpeedCar_ = minSpeedCar;
	isAngry_ = isAngry;
	distanceForWin_ = distanceForWin;
}

LvlInfo::LvlInfo() {
	countEnemyCar_ = 0;
	maxSpeedCar_ = 0;
	minSpeedCar_ = 0;
	isAngry_ = false;
	distanceForWin_ = 0;
}

LvlInfo::LvlInfo(DifficultyMode mode) {
	switch (mode)
	{
	case DIFFICALTY_EASY:
		countEnemyCar_ = EASYCOUNTCAR;
		maxSpeedCar_ = EASYMAXSPEED;
		minSpeedCar_ = EASYMINSPEED;
		isAngry_ = false;
		distanceForWin_ = EASYDISTANCE;
		break;
	case DIFFICALTY_NORMAL:
		countEnemyCar_ = NORMALCOUNTCAR;
		maxSpeedCar_ = NORMALMAXSPEED;
		minSpeedCar_ = NORMALMINSPEED;
		isAngry_ = true;
		distanceForWin_ = NORMALDISTANCE;
		break;
	case DIFFICALTY_HARD:
		countEnemyCar_ = HARDCOUNTCAR;
		maxSpeedCar_ = HARDMAXSPEED;
		minSpeedCar_ = HARDMINSPEED;
		isAngry_ = true;
		distanceForWin_ = HARDDISTANCE;
		break;
	default:
		break;
	}
}