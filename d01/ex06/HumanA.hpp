#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

public:
    HumanA( std::string const & name, Weapon & weapon );
    ~HumanA( void );

    void    attack( void );

 private:
    std::string     _name;
    Weapon         & _weapon;

};

#endif
