#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <atltime.h>
#include <windows.h>
#include <list>
#include <conio.h>
#include <vector>
using namespace std;

int const MS_PER_FRAME = 50;

enum Keys {
	KEYS_RIGHTKEY = 77,
	KEYS_LEFTKEY = 75,
	KEYS_UPKEY = 72,
	KEYS_DOWNKEY = 80,
	KEYS_ENTER = 13,
	KEYS_ESC = 27
};


enum Direction {
	DIRECTION_NORTH,
	DIRECTION_SOUTH,
	DIRECTION_WEST,
	DIRECTION_EAST
};