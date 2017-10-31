#ifndef COM_COMPANY_MODULE_ROAD_H
#define COM_COMPANY_MODULE_ROAD_H

#include "Road.h"

#endif 

void Road::printStrip() {
	int h = getHiegthRoad();
	int w = getWidthRoad();

	bool stripPrint = true;
	Color color1 = COLOR_WHITE;
	Color color2 = COLOR_DARKGRAY;

	if (strip_ < STRIP_LENGTH)
	{
		for (size_t i = 0; i < h; i++)
		{
			if ((i - strip_) % STRIP_LENGTH == 0)
			{
				stripPrint = !stripPrint;
			}
			if (stripPrint)
			{
				Console::SetColor(color2, color2);
			}
			else Console::SetColor(color1, color1);
			Console::SetCursorPosition(w / getRoadwayCount() + border_->getLeftBorder(), i);
			cout << char(RECTANGLE_SYMBOL);
		}
	}
	else
	{
		for (size_t i = 0; i < h; i++)
		{
			if ((i - strip_ - STRIP_LENGTH) % STRIP_LENGTH == 0)
			{
				stripPrint = !stripPrint;
			}
			if (stripPrint)
			{
				Console::SetColor(color1, color1);
			}
			else Console::SetColor(color2, color2);
			Console::SetCursorPosition(w / getRoadwayCount() + border_->getLeftBorder(), i);
			cout << char(RECTANGLE_SYMBOL);
		}


	}



}

void Road::print() {
	int h = getHiegthRoad();
	int w = getWidthRoad();

	for (size_t i = 0; i < h; i++)
	{
		Console::SetColor(COLOR_GREEN, COLOR_GREEN);
		cout << char(RECTANGLE_SYMBOL) << char(RECTANGLE_SYMBOL) << char(RECTANGLE_SYMBOL);
		for (size_t j = 0; j < w; j++)
		{

			Console::SetCursorPosition(j + border_->getLeftBorder(), i);
			Console::SetColor(COLOR_DARKGRAY, COLOR_DARKGRAY);
			cout << char(RECTANGLE_SYMBOL);

		}
		Console::SetColor(COLOR_GREEN, COLOR_GREEN);
		cout << char(RECTANGLE_SYMBOL) << char(RECTANGLE_SYMBOL) << char(RECTANGLE_SYMBOL);

	}
	printStrip();
}

void Road::move(int moveCount) {
	for (size_t i = 0; i < moveCount; i++)
	{
		if (++strip_ >= STRIP_LENGTH * 2)
		{
			strip_ = START_STRIP_POSITION;
		}
	}

	printStrip();
}

int Road::getWidthRoad() const {
	return ROAD_RIGTH_COORD - ROAD_LEFT_COORD + 1;
}

int Road::getHiegthRoad() const {
	return ROAD_BOTTOM_COORD + 1;
}
int Road::getRoadwayCount() const {
	return ROADWEY_COUNT;
}

shared_ptr<RoadBorder> Road::getBorder() const {
	return border_;
}

Road::Road() {
	strip_ = START_STRIP_POSITION;
	border_ = shared_ptr<RoadBorder>(
				new RoadBorder(
						ROAD_LEFT_COORD,
						ROAD_RIGTH_COORD,
						ROAD_BOTTOM_COORD,
						ROAD_TOP_COORD
						)
					);
}

Road::~Road() {
	
}


void Road::handleEvent(IPublisher* publisher) {
	Player p = dynamic_cast<Player&>(*publisher);
	int moveCount = p.getDx();
	move(moveCount);

}

void Road::addPublisher(IPublisher * publisher)
{
}
