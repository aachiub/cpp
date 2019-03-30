
#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim {

public:
    Victim( std::string const & name );
    Victim( Victim const & victim );
    ~Victim( void );

    Victim & operator = ( Victim const & rhs );

    virtual void getPolymorphed( void ) const;

    std::string & getName( void );
    void setName( std::string const & name );

private:
    std::string     _name;
};

std::ostream & operator << ( std::ostream & os, Victim & rhs );

#endif
