/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:27 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 16:15:09 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP 

#include <iostream>

// Colors
#define NORMAL	"\033[0m"
#define BLACK	"\033[1;30m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"

// Frag4TP Constants
#define FRAG4TP		"FRAG4_TP "

#define	MAXATTACKS		5
#define	MAXHUMTS		5
#define	MAXFRAGTRAPS	5
#define	MAXLEVELS		5

#define	VAULTPENALTY	25
#define	ARMORPENALTY	5

#define	MSG_VAULTATTACK		" Not enough energy to attack "
#define	MSG_MELEEATTACK 	" Melee attack penalty applied  "
#define	MSG_RANGEATTACK 	" Range attack penalty applied  "
#define	MSG_ARMORDAMAGE 	" Armor repair penalty applied "
#define	MSG_OUTOFENERGY 	"  ... Is now running out of energy."

// Frag4TP Class
class ScavTrap {

public:

	// Coplien's form compliant
	ScavTrap ( void );
	ScavTrap ( std::string const & name );
	~ScavTrap( void );
	ScavTrap ( ScavTrap const & src );
	ScavTrap & operator = ( ScavTrap const & rhs );

	// member functions
	void 		setName( std::string const & name );
	std::string  getName( void ) const;
	
	void 	setLevel( int const & level );
	void 	setHitPoints( int const & hPoints );
	void 	setEnergyPoints( int const & ePoints );
	int 	getLevel( void ) const;
	int 	getHitPoints( void ) const;
	int 	getEnergyPoints( void ) const;
	
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
	void rangedAttack( std::string const & target );
	void meleeAttack( std::string const & target );
	void dawnAttack( std::string const & target );
	void internetAttack( std::string const & target );
	void victoryAttack( std::string const & target );
	
	void vaulthunter_dot_exe(std::string const & target);
	bool takePenalty( unsigned int amount );

	void displayStatus( void ) const;

private:

	std::string	_name;
	int 		_level;
	int 		_hitPoints;
	int 		_energyPoints;

	// static consts
	static const int _meleeAttackDamage 	= 30;
	static const int _rangedAttackDamage 	= 20;
	static const int _internetAttackDamage 	= 15;
	static const int _dawnAttackDamage 		= 10;
	static const int _victoryAttackDamage 	= 30;
	static const int _armorDamageReduction 	= 5;

	static const int _maxHitPoints 			= 100;
	static const int _maxEnergyPoints 		= 100;


};

#endif
