#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( ) : AWeapon("Plasma Rifle", 5, 21) {
    return ;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & PlasmaRifle ) {
    *this = PlasmaRifle;
    return ;
}

PlasmaRifle::~PlasmaRifle( void ) {
    return ;
}

PlasmaRifle & PlasmaRifle::operator = ( PlasmaRifle const & rhs ) {
    AWeapon::operator=(rhs);
    return *this;
}

void PlasmaRifle::attack( void ) const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

/*
std::ostream & operator << ( std::ostream  & os, PlasmaRifle & rhs  ) {
    return os << "Plasma Rifle " << rhs.getName() << std::endl;
}
*/