#ifndef COM_COMPANY_MODULE_CONST_H
#define COM_COMPANY_MODULE_CONST_H

#include "Const.h"

#endif 


class LvlInfo {

public:
	int getCountEnemy() const;
	int getMaxSpeedCar() const;
	int getMinSpeedCar() const;
	bool getIsAngry() const;
	int getDistanceForWin() const;

	LvlInfo(int countEnemyCar,
		int maxSpeedCar,
		int minSpeedCar,
		bool isAngry,
		int distanceForWin
	);

	LvlInfo();

	LvlInfo(DifficultyMode mode);

private:
	int countEnemyCar_;
	int maxSpeedCar_;
	int minSpeedCar_;
	bool isAngry_;
	int distanceForWin_;
};