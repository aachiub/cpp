#include <iostream>
#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"


Character::Character( std::string const &name ) : _name(name), _weapon(NULL), _ap(40) {
	return;
}

Character::Character( Character &src ) {
   	*this = src;
	return;
}

Character::~Character( void ) {
	return;
}

Character &Character::operator=( Character const &rhs ) {
    if ( this != &rhs ) {
        this->_name = rhs.getName();
        this->_weapon = rhs.getWeapon();
        this->_ap = rhs.getAP();
    }
	return (*this);
}

std::string		Character::getName( void ) const {
	return ( this->_name );
}

AWeapon	*Character::getWeapon( void ) const {
	return ( this->_weapon );
}

int	Character::getAP( void ) const {
	return ( this->_ap );
}

void			Character::recoverAP( void ) {
	if ( ( this->_ap += 10 ) > 40)
		this->_ap = 40;
}

void			Character::equip( AWeapon *weapon ) {
	this->_weapon = weapon;
	return;
}

void			Character::attack( Enemy *enemy ) {

    if ( this->getWeapon() && enemy->getHP() )
		if ( this->getAP() != 0 && ( this->getAP() >= this->getWeapon()->getAPCost() ) ) {

			std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
			
            this->getWeapon()->attack();
			enemy->takeDamage( this->getWeapon()->getDamage() );
			
            this->_ap -= this->getWeapon()->getAPCost();
			
            if ( enemy->getHP() <= 0 )
				delete enemy;
		}
}

std::ostream & operator<<( std::ostream &os, Character const &rhs )
{
	os << rhs.getName() << " has "  << rhs.getAP();
    if (rhs.getWeapon())
		os << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		os << " AP and is unarmed" << std::endl;

    return ( os );
}
