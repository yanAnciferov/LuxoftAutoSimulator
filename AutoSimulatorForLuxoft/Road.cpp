#include "Road.h"


void Road::print() {
	int h = getHiegthRoad();
	int w = getWidthRoad();

	for (size_t i = 0; i < h; i++)
	{
		Console::SetColor(COLOR_GREEN, COLOR_GREEN);
		cout << char(219) << char(219) << char(219);
		for (size_t j = 0; j < w; j++)
		{

			Console::SetCursorPosition(j + 3, i);
			Console::SetColor(COLOR_DARKGRAY, COLOR_DARKGRAY);
			cout << char(219);

		}
		Console::SetColor(COLOR_GREEN, COLOR_GREEN);
		cout << char(219) << char(219) << char(219);

	}
	printStrip();
}

void Road::move(int moveCount) {
	for (size_t i = 0; i < moveCount; i++)
	{
		if (++_strip >= 8)
		{
			_strip = 0;
		}
	}

	printStrip();
}

int Road::getWidthRoad() {
	return 41;
}

int Road::getHiegthRoad() {
	return 56;
}


RoadBorder&  Road::getBorder() {
	return *_border;
}

Road::Road() {
	_strip = 0;
	_border = new RoadBorder(3, 43, 55, 0);
}

Road::~Road() {
	delete _border;
}


void Road::handleEvent(IPublisher* publisher) {
	Player p = dynamic_cast<Player&>(*publisher);
	int moveCount = p.getDx();
	move(moveCount);

}

void Road::addPublisher(IPublisher * publisher)
{
}
