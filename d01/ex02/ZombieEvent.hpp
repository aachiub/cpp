#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

public:
    ZombieEvent( void );
    ZombieEvent( std::string const & type );
    ZombieEvent( ZombieEvent const & src );
    ~ZombieEvent( void );

    ZombieEvent & operator = ( ZombieEvent const & rhs );


    std::string & getType( void );
    void setType( std::string const & name );
    
    Zombie* newZombie( std::string name );

private:
    std::string     _type;
};

std::ostream & operator << ( std::ostream & os, ZombieEvent & rhs );

#endif
