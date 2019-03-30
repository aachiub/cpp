#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class	Enemy {

	public:

		Enemy (void );
		Enemy( int hp, std::string const &type );
		Enemy( Enemy &src );
		virtual ~Enemy( void );

		Enemy &operator=(Enemy const &rhs);

		std::string		getType( void ) const;
		int				getHP( void ) const;
		void			setHP( int hp );

		virtual void	takeDamage( int damage );

	private:
		int				_hp;
		std::string		_type;
};

#endif
