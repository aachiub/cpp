#ifndef MONITOR_HPP
# define MONITOR_HPP

#include <sys/time.h>
#include <vector>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Monitor
{
public:
	Monitor(std::string mode);
	~Monitor();
	void run();

private:
	Monitor();
	Monitor(Monitor const & src);
	Monitor & operator=(Monitor const & rhs);

	// base
	std::vector<IMonitorModule *>	_module;
	IMonitorDisplay	*				_display;

	// time-based display
	struct timeval					_loopStart;
	struct timeval					_loopStop;
	int								_frameRate;

	void init();
	bool shouldUpdate();
	void update();
	void render();
};

#endif