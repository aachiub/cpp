

#include "Zombie.hpp"


Zombie::Zombie( void ) : _name("Unnamed"){
    return ;
}

Zombie::Zombie( std::string const & name, std::string const & type ) : _name( name ), _type( type ) {
    return ;
}

Zombie::Zombie( Zombie const & src ) {
    *this = src;
    return ;
}

Zombie::~Zombie( void ) {
    return ;
}

Zombie & Zombie::operator = ( Zombie const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}


std::string & Zombie::getName( void ) {
    return this->_name;
}

void Zombie::setName( std::string const & name ) {
    this->_name = name;
    return ;
}

std::string & Zombie::getType( void ) {
    return this->_type;
}

void Zombie::setType( std::string const & type ) {
    this->_type = type;
    return ;
}

std::ostream & operator << ( std::ostream  & os, Zombie & rhs  ) {
    return os << "<"  << rhs.getName() << " (" << rhs.getType() << ")>";
}

void Zombie::announce( void ) {
    std::cout << *this << TXTRED << " Need More Blooooooooood !..." << TXTNORMAL << std::endl;
}

