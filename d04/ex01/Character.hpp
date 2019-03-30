
#ifndef CHARACTER_H
 #define CHARACTER_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character {

	public:

		Character( void );
		Character( std::string const &name );
		Character (Character &src );
		virtual ~Character( void );

		Character &operator=( Character const &rhs );

		void recoverAP( void );
		void equip( AWeapon* weapon);
		void attack( Enemy* enemy);

		std::string	getName( void ) const;

		int	        getAP( void ) const;
		AWeapon		*getWeapon( void ) const;


	private:

		std::string		_name;
		AWeapon			*_weapon;
		int				_ap;

};

std::ostream & operator<<( std::ostream & os, Character const & rhs );

#endif