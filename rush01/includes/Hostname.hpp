#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

#include <string>
#include "IMonitorModule.hpp"

class Hostname : public IMonitorModule
{
public:
	Hostname(IMonitorDisplay * display);
	~Hostname();

	void getInfo();
	void drawInfo(IMonitorDisplay * display);

private:
	Hostname();
	Hostname(Hostname const & src);
	Hostname & operator=(Hostname const & rhs);

	std::string _hostname;
	std::string _username;
};

#endif