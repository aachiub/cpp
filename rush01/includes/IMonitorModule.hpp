#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <string>
#include "IMonitorDisplay.hpp"

class IMonitorModule
{
public:
	virtual ~IMonitorModule();
	virtual void getInfo() = 0;
	virtual void drawInfo(IMonitorDisplay * display) = 0;
};

#endif