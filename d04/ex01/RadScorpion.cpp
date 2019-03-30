
#include <iostream>
#include "RadScorpion.hpp"
#include "Enemy.hpp"

RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion &obj) : Enemy(obj) {
	std::cout << "* click click click *" << std::endl;
	*this = obj;
	return;
}

RadScorpion::~RadScorpion( void ) {
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

RadScorpion & RadScorpion::operator=( RadScorpion const &rhs ) {
	
    Enemy::operator=(rhs);
	
    return (*this);
}