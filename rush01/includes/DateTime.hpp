#ifndef DATETIME_HPP
# define DATETIME_HPP

#include <string>
#include "IMonitorModule.hpp"

class DateTime : public IMonitorModule
{
public:
	DateTime(IMonitorDisplay * display);
	~DateTime();

	void getInfo();
	void drawInfo(IMonitorDisplay * display);

private:
	DateTime();
	DateTime(DateTime const & src);
	DateTime & operator=(DateTime const & rhs);

	std::string _dateTime;
};

#endif