#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

#define TXTNORMAL	"\033[0m"
#define TXTRED		"\033[1;31m"

class Zombie {

public:
    Zombie( void );
    Zombie( std::string const & name, std::string const & type );
    Zombie( Zombie const & src );
    ~Zombie( void );

    Zombie & operator = ( Zombie const & rhs );

    std::string & getName( void );
    void setName( std::string const & name );
    std::string & getType( void );
    void setType( std::string const & name );

    void announce( void );

private:

    std::string     _name;
    std::string     _type;
};

#endif
