#pragma once

class IUpdate
{
public:
	virtual bool update() = 0;
	virtual ~IUpdate() {};
};