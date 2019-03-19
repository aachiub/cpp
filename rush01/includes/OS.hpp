#ifndef OS_HPP
# define OS_HPP

#include <string>
#include "IMonitorModule.hpp"

class OS : public IMonitorModule
{
public:
	OS(IMonitorDisplay * display);
	~OS();

	void getInfo();
	void drawInfo(IMonitorDisplay * display);

private:
	OS();
	OS(OS const & src);
	OS & operator=(OS const & rhs);

	std::string _type;
	std::string _release;
	std::string _version;

	void getType();
	void getRelease();
	void getVersion();
};

#endif