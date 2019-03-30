#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class	SuperMutant : public Enemy
{

	public:
    	SuperMutant( void );
		SuperMutant( SuperMutant &src );
		virtual ~SuperMutant( void);

		SuperMutant & operator=( SuperMutant const & rhs );

		virtual void takeDamage( int damage );

};

#endif