#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <string>
#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
public:
	Network(IMonitorDisplay * display);
	~Network();

	void getInfo();
	void drawInfo(IMonitorDisplay * display);

private:
	Network();
	Network(Network const & src);
	Network & operator=(Network const & rhs);

	unsigned long _packageInTick;
	unsigned long _packageOutTick;
	unsigned long _mbInTick;
	unsigned long _mbOutTick;

	unsigned long _packageIn;
	unsigned long _packageOut;
	unsigned long _mbIn;
	unsigned long _mbOut;

	std::string _package;
	std::string _mb;
};

#endif