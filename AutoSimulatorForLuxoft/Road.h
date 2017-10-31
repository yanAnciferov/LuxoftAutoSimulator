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

	int getWidthRoad() const;

	int getHiegthRoad() const;

	int getRoadwayCount() const;

	shared_ptr<RoadBorder> getBorder() const;

	Road();

	~Road();

	virtual void handleEvent(IPublisher* publisher) override;

	virtual void addPublisher(IPublisher * publisher) override;

private:
	shared_ptr<RoadBorder> border_;
	int strip_;

	void printStrip();

};

