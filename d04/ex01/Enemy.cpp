#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"


Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type) {
	return;
}

Enemy::Enemy(Enemy &src) {
    if ( this != &src )
	    *this = src;
	return;
}

Enemy::~Enemy(void) {
	return;
}

Enemy &Enemy::operator=(Enemy const &rhs) {
	this->_hp = rhs._hp;
	this->_type = rhs._type;

	return (*this);
}

std::string	Enemy::getType() const {
	return ( this->_type );
}

int	Enemy::getHP() const {
	return ( this->_hp );
}

void Enemy::takeDamage( int damage ) {

    /*
    int i = 0;

	if (amount < 0)
		return;
	else if (amount > this->_hp )
		i = this->_hp;
	else
		i = amount;
	this->_hp = this->_hp - i;
	if (this->_hp < 0)
		this->_hp = 0;

    */
	if ( damage > 0 )
    	this->_hp =  ( damage > this->getHP() ) ? 0 : damage;
	return;
}

void Enemy::setHP( int hp ) {
	this->_hp = hp;
	return;
}