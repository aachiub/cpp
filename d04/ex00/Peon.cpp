
#include <iostream>
#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon( std::string const & name ) : Victim( name ), _name( name ) {
 
    std::cout << "Zog zog." << std::endl;

    return ;

}

Peon::Peon( Peon const & peon ) : Victim( peon ) {
    *this = peon;
    return ;
}

Peon::~Peon( void ) {
    std::cout << "Bleuark..." << std::endl;
    return ;
}

Peon & Peon::operator = ( Peon const & rhs ) {
    this->_name = rhs._name;
    return *this;
}

std::string & Peon::getName( void ) {
    return this->_name;
}

void Peon::setName( std::string const & name ) {
    this->_name = name;
    return ;
}

void Peon::getPolymorphed( void ) const {
    std::cout << _name << " has been turned into a pink pony !" << std::endl;
}

