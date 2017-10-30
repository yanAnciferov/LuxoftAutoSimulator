#ifndef COM_COMPANY_MODULE_HEADER_H
#define COM_COMPANY_MODULE_HEADER_H

#include "Header.h"

#endif

#ifndef COM_COMPANY_MODULE_MYTYPES_H
#define COM_COMPANY_MODULE_MYTYPES_H

#include "MyTypes.h"

#endif

class Road : public ISubscriber
{


public:

	void print();

	void move(int moveCount);

	int getWidthRoad();

	int getHiegthRoad();

	int getRoadwayCount();

	RoadBorder& getBorder();

	Road();

	~Road();

	virtual void handleEvent(IPublisher* publisher) override;

	virtual void addPublisher(IPublisher * publisher) override;

private:
	RoadBorder* border_;
	int strip_;

	void printStrip();

};

