#ifndef COM_COMPANY_MODULE_HEADER_H
#define COM_COMPANY_MODULE_HEADER_H

#include "Header.h"

#endif

#ifndef COM_COMPANY_MODULE_MYTYPES_H
#define COM_COMPANY_MODULE_MYTYPES_H

#include "MyTypes.h"

#endif

class Timer: public IUpdate {

public:
	virtual bool update() override;

	clock_t getTime();

	void pause();

	bool isPause();

private:
	clock_t clock1_;
	clock_t clock2_;
	clock_t timer_;
	bool start_ = false;
	bool pause_ = false;
};