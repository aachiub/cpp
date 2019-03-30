
#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class	RadScorpion : public Enemy {

	public:

		RadScorpion( void );
		RadScorpion( RadScorpion &src );
		virtual ~RadScorpion( void) ;

		RadScorpion & operator=( RadScorpion const &rhs );

};

#endif

