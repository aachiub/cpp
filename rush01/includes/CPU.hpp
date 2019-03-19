#ifndef CPU_HPP
# define CPU_HPP

#include <string>
#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
public:
	CPU(IMonitorDisplay * display);
	~CPU();

	void getInfo();
	void drawInfo(IMonitorDisplay * display);

private:
	CPU();
	CPU(CPU const & src);
	CPU & operator=(CPU const & rhs);

	unsigned long long _userTick;
	unsigned long long _systemTick;
	unsigned long long _idleTick;

	std::string _model;
	std::string _cores;
	std::string _user;
	std::string _system;
	std::string _idle;

	void getModel();
	void getCores();
};

#endif