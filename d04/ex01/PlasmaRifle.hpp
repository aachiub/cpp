
#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon{

public:
    PlasmaRifle(void);
    PlasmaRifle( PlasmaRifle const & PlasmaRifle );
    virtual ~PlasmaRifle(void);

    PlasmaRifle & operator = ( PlasmaRifle const & rhs );

    void attack() const;

private:
   std::string  _attackSound;
};

std::ostream & operator << ( std::ostream & os, PlasmaRifle & rhs );

#endif
