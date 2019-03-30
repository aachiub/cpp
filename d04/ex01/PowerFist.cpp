#include <iostream>
#include "AWeapon.hpp"
#include "PowerFist.hpp"

PowerFist::PowerFist( ) : AWeapon("Power Fist", 8, 50) {
    return ;
}

PowerFist::PowerFist( PowerFist const & PowerFist ) {
    *this = PowerFist;
    return ;
}

PowerFist::~PowerFist( void ) {
    return ;
}

PowerFist & PowerFist::operator = ( PowerFist const & rhs ) {
    AWeapon::operator=(rhs);
    return *this;
}

void PowerFist::attack( void ) const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
/*
std::ostream & operator << ( std::ostream  & os, PowerFist & rhs  ) {
    return os << "Plasma Rifle " << rhs.getName() << std::endl;
}
*/