/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:27 by aachir            #+#    #+#             */
/*   Updated: 2019/01/11 21:41:27 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

#define FRAG4TP		"FRAG4_TP "

#define TXTNORMAL	"\033[0m"
#define TXTBLACK	"\033[1;30m"
#define TXTRED		"\033[1;31m"
#define TXTGREEN	"\033[1;32m"
#define TXTYELLOW	"\033[1;33m"
#define TXTBLUE		"\033[1;34m"
#define TXTMAGENTA	"\033[1;35m"

#define	MAXATTACKS		10
#define	MAXHUMTS		5
#define	MAXFRAGTRAPS	10

#define	VAULTPENALTY	25

typedef enum 	e_penaly {
	VAULT = 0,
	MELEE,
	RANGE,
	ARMOR
}				t_penalty;

#define	MSG_VAULTATTACK		" Not enough energy to attack "
#define	MSG_MELEEATTACK 	" Melee attack penalty applied  "
#define	MSG_RANGEATTACK 	" Range attack penalty applied  "
#define	MSG_ARMORDAMAGE 	" Armor repair penalty applied "
#define	MSG_OUTOFENERGY 	"  ... Is now running out of energy. BYE "

class FragTrap {

public:

	// Coplien's form compliant
	FragTrap ( void );
	FragTrap ( std::string const & name );
	~FragTrap( void );
	FragTrap ( FragTrap const & src );
	FragTrap & operator = ( FragTrap const & rhs );

	// member functions
	void 			setName( std::string const & name );
	std::string  	getName( void ) const;
	void 			setLevel( int const & level );
	int 			getLevel( void ) const;
	void 			setHitPoints( int const & hPoints );
	int 			getHitPoints( void ) const;
	void 			setEnergyPoints( int const & ePoints );
	int 			getEnergyPoints( void ) const;
	int 			getRangeAttackDamage( void ) const;
	int 			getMeleeAttackDamage( void ) const;
	bool 			setAttackPenalty( t_penalty const & penalty );

	void rangedAttack( std::string const & target );
	void meleeAttack( std::string const & target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

private:

	std::string	_name;
	int 		_level;
	int 		_hitPoints;
	int 		_energyPoints;

	static const int _maxHitPoints 			= 100;
	static const int _maxEnergyPoints 		= 100;
	static const int _meleeAttackDamage 	= 30;
	static const int _rangedAttackDamage 	= 20;
	static const int _armorDamageReduction 	= 5;

};

#endif
