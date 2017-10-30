#include "Road.h"

void Road::printStrip() {
	int h = getHiegthRoad();
	int w = getWidthRoad();

	bool stripPrint = true;
	Color color1 = COLOR_WHITE;
	Color color2 = COLOR_DARKGRAY;

	if (strip_ < 4)
	{
		for (size_t i = 0; i < h; i++)
		{
			if ((i - strip_) % 4 == 0)
			{
				stripPrint = !stripPrint;
			}
			if (stripPrint)
			{
				Console::SetColor(color2, color2);
			}
			else Console::SetColor(color1, color1);
			Console::SetCursorPosition(w / 2 + 3, i);
			cout << char(219);
		}
	}
	else
	{
		for (size_t i = 0; i < h; i++)
		{
			if ((i - strip_ - 4) % 4 == 0)
			{
				stripPrint = !stripPrint;
			}
			if (stripPrint)
			{
				Console::SetColor(color1, color1);
			}
			else Console::SetColor(color2, color2);
			Console::SetCursorPosition(w / 2 + 3, i);
			cout << char(219);
		}


	}



}

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
		if (++strip_ >= 8)
		{
			strip_ = 0;
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
	return *border_;
}

Road::Road() {
	strip_ = 0;
	border_ = new RoadBorder(3, 43, 55, 0);
}

Road::~Road() {
	delete border_;
}


void Road::handleEvent(IPublisher* publisher) {
	Player p = dynamic_cast<Player&>(*publisher);
	int moveCount = p.getDx();
	move(moveCount);

}

void Road::addPublisher(IPublisher * publisher)
{
}
