#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon: public Victim {

public:
    Peon( std::string const & name );
    Peon( Peon const & peon );
    ~Peon( void );

    Peon & operator = ( Peon const & rhs );

    void getPolymorphed( void ) const;

    std::string & getName( void );
    void setName( std::string const & name );

private:
    std::string     _name;
};

//std::ostream & operator << ( std::ostream & os, Peon & rhs );

#endif
