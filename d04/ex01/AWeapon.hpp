
#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon {

public:
    AWeapon(void);
    AWeapon(std::string const & name, int apcost, int damage);
    AWeapon( AWeapon const & AWeapon );
    virtual ~AWeapon(void);

    AWeapon & operator = ( AWeapon const & rhs );

    virtual std::string getName() const;
    
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;

private:
    std::string  _name;
    int          _apcost;
    int          _damage;
};

std::ostream & operator << ( std::ostream & os, AWeapon & rhs );

#endif
