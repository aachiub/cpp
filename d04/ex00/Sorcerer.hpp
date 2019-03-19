
#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {

public:
    Sorcerer( std::string const & name, std::string const title );
    Sorcerer( Sorcerer const & sorcerer );
    ~Sorcerer( void );

    Sorcerer & operator = ( Sorcerer const & rhs );

    std::ostream & operator << ( std::ostream & os );

    void polymorph(Victim const & victim) const;

    std::string & getName( void );
    void setName( std::string const & name );
    std::string & getTitle( void );
    void setTitle( std::string const & name );

private:
    std::string     _name;
    std::string     _title;
};

std::ostream & operator << ( std::ostream & os, Sorcerer & rhs );

#endif
