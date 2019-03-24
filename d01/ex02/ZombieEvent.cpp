
#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"


ZombieEvent::ZombieEvent( void ) {

    return ;
}
ZombieEvent::ZombieEvent( std::string const & type ) : _type( type ) {
    return ;
}

ZombieEvent::ZombieEvent( ZombieEvent const & src ) {
    *this = src;
    return ;
}

ZombieEvent::~ZombieEvent( void ) {
    return ;
}

ZombieEvent & ZombieEvent::operator = ( ZombieEvent const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

std::string & ZombieEvent::getType( void ) {
    return this->_type;
}

void ZombieEvent::setType( std::string const & type ) {
    this->_type = type;
    return ;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    return ( new Zombie( name, this->_type ) );
}
