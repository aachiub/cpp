#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "IMonitorDisplay.hpp"

class Graphic : public IMonitorDisplay
{
public:
	Graphic();
	~Graphic();
	bool isClose();
	void putInfo(std::string str);
	void editY(int y);
	void render();

private:
	Graphic(Graphic const & src);
	Graphic & operator=(Graphic const & rhs);

	sf::RenderWindow 	_screen;
	int					_y;
};

#endif