#pragma once
#include "Observer.h"
#include "Player.h"
#include "console.h"
#include "RoadBorder.h"


class Road : public ISubscriber
{


	RoadBorder* border;
	
	void printStrip() {
		int h = getHiegthRoad();
		int w = getWidthRoad();
		
		bool stripPrint = true;
		Color color1 = COLOR_WHITE;
		Color color2 = COLOR_DARKGRAY;
		
			if (_strip < 4)
			{
				for (size_t i = 0; i < h; i++)
				{
					if ((i - _strip) % 4 == 0)
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
			}else
			{
				for (size_t i = 0; i < h; i++)
				{
					if ((i - _strip - 4) % 4 == 0)
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

	int _strip;
	
public:

	void print();

	void move(int moveCount);

	int getWidthRoad();

	int getHiegthRoad();

	
	RoadBorder& getBorder();

	Road();

	~Road();


	virtual void handleEvent(IPublisher* publisher) override;

	// Inherited via ISubscriber
	virtual void addPublisher(IPublisher * publisher) override;
};

