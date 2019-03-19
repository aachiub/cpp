
#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer( std::string const & name, std::string const title ) : _name( name ), _title( title ) {

    std::cout << _name <<  ", " << _title << ", is born !" << std::endl;
    return ;
}

Sorcerer::Sorcerer( Sorcerer const & sorcerer ) {
    *this = sorcerer;
    return ;
}

Sorcerer::~Sorcerer( void ) {
    std::cout << _name <<  ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
    return ;
}

Sorcerer & Sorcerer::operator = ( Sorcerer const & rhs ) {
    this->_name = rhs._name;
    this->_title = rhs._title;
    return *this;
}

std::string & Sorcerer::getName( void ) {
    return this->_name;
}

void Sorcerer::setName( std::string const & name ) {
    this->_name = name;
    return ;
}

std::string & Sorcerer::getTitle( void ) {
    return this->_title;
}

void Sorcerer::setTitle( std::string const & title ) {
    this->_title = title;
    return ;
}


void Sorcerer::polymorph(Victim const & victim) const {
    victim.getPolymorphed();
    return ;
}

std::ostream & operator << ( std::ostream  & os, Sorcerer & rhs  ) {
    return os << "I am " << rhs.getName() <<  ", "  <<  rhs.getTitle() \
                << ", " << " and I like ponies !" << std::endl;
}
