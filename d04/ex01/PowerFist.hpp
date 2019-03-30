
#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon{

public:
    PowerFist(void);
    PowerFist( PowerFist const & PowerFist );
    virtual ~PowerFist(void);

    PowerFist & operator = ( PowerFist const & rhs );

    void attack() const;

private:
   std::string  _attackSound;
};

std::ostream & operator << ( std::ostream & os, PowerFist & rhs );

#endif
