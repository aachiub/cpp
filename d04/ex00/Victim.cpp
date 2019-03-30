
#include <iostream>
#include "Victim.hpp"

Victim::Victim( std::string const & name ) : _name( name ) {

    std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
    return ;

}

Victim::Victim( Victim const & victim ) {
    *this = victim;
    return ;
}

Victim::~Victim( void ) {
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
    return ;
}

Victim & Victim::operator = ( Victim const & rhs ) {
    this->_name = rhs._name;
    return *this;
}

std::string & Victim::getName( void ) {
    return this->_name;
}

void Victim::setName( std::string const & name ) {
    this->_name = name;
    return ;
}

void Victim::getPolymorphed( void ) const {
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator << ( std::ostream  & os, Victim & rhs  ) {
    return os << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
}
