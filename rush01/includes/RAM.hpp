#ifndef RAM_HPP
# define RAM_HPP

#include <string>
#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
public:
	RAM(IMonitorDisplay * display);
	~RAM();

	void getInfo();
	void drawInfo(IMonitorDisplay * display);

private:
	RAM();
	RAM(RAM const & src);
	RAM & operator=(RAM const & rhs);

	std::string _total;
	std::string _free;
	std::string _active;
	std::string _inactive;
	std::string _wired;
};

#endif