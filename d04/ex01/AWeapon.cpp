
#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : \
             _name( name ), _apcost( apcost ), _damage( damage ) {
    return ;

}

AWeapon::AWeapon( AWeapon const & AWeapon ) {
    *this = AWeapon;
    return ;
}

AWeapon::~AWeapon( void ) {
    return ;
}

AWeapon & AWeapon::operator = ( AWeapon const & rhs ) {
    if ( this != &rhs ) {
       this->_name = rhs.getName();
       this->_apcost = rhs.getAPCost();
       this->_damage = rhs.getDamage();
    }
    return *this;
}

std::string AWeapon::getName( void ) const {
    return ( this->_name );
}

int AWeapon::getAPCost( void ) const {
    return ( this->_apcost );
}

int AWeapon::getDamage( void ) const {
     return ( this->_damage );
}

std::ostream & operator << ( std::ostream  & os, AWeapon & rhs  ) {
    return os << "Weapon " << rhs.getName() << std::endl;
}
