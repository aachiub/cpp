#ifndef SHELL_HPP
# define SHELL_HPP

#include <ncurses.h>
#include <string>
#include "IMonitorDisplay.hpp"

class Shell : public IMonitorDisplay
{
public:
	Shell();
	~Shell();
	bool isClose();
	void putInfo(std::string str);
	void editY(int y);
	void render();

private:
	Shell(Shell const & src);
	Shell & operator=(Shell const & rhs);

	WINDOW *	_screen;
	int			_y;
};

#endif