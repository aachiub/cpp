
#include <iostream>
#include "SuperMutant.hpp"
#include "Enemy.hpp"
 
SuperMutant::SuperMutant( void ) : Enemy( 170, "Super Mutant" ) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;

	return;
}

SuperMutant::SuperMutant( SuperMutant &src ) : Enemy( src ) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;

	*this = src;
	return;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Aaargh ..." << std::endl;
	
    return;
}

SuperMutant &SuperMutant::operator=( SuperMutant const &rhs ) {
	Enemy::operator=( rhs);

	return (*this);
}

void SuperMutant::takeDamage( int amount ) {
    int i;
	if ( amount < 3)
		return;

	else if (amount > (this->getHP() + 3) )
		i = this->getHP() + 3;
	else
		i = amount;
	this->setHP(this->getHP() - i + 3);
	if (this->getHP() < 0)
		this->setHP(0);
/*
	int min = 3;
   	if ( amount > min )
    	this->setHP( this->getHP() - ( amount > this->getHP() + min)  ? 0 : amount - min );
*/
	return;
}