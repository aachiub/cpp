/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:27 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 16:15:19 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

#define FRAG4TP		"FRAG4_TP "

#define NORMAL	"\033[0m"
#define BLACK	"\033[1;30m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"

#define	MAXATTACKS		5
#define	MAXHUMTS		5
#define	MAXFRAGTRAPS	5
#define	MAXLEVELS		5

#define	VAULTPENALTY	25
#define	ARMORPENALTY	5

#define	MELEEDAMAGE		30
#define	RANGEDAMAGE		20
#define	INTERNETDAMAGE	15
#define	DAWNDAMAGE		10
#define	VICTORYDAMAGE	30

#define MAXHITPOINTS	100
#define MAXENERGYPOINTS	100

typedef enum 	e_attack {
	ATTACK0 = 0,
	MELEE,
	RANGE,
	INTERNET,
	DAWN,
	VICTORY,
	VAULT,
	ARMOR
}				t_attack;

#define	MSG_VAULTATTACK		" Not enough energy to attack "
#define	MSG_MELEEATTACK 	" Melee attack penalty applied  "
#define	MSG_RANGEATTACK 	" Range attack penalty applied  "
#define	MSG_ARMORDAMAGE 	" Armor repair penalty applied "
#define	MSG_OUTOFENERGY 	"  ... Is now running out of energy."

class FragTrap {

public:

	// Coplien's form compliant
	FragTrap ( void );
	FragTrap ( std::string const & name );
	~FragTrap( void );
	FragTrap ( FragTrap const & src );
	FragTrap & operator = ( FragTrap const & rhs );

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
	
	bool setAttackPenalty( t_attack const & attack );
	bool applyPenalty( unsigned int amount );

	void vaulthunter_dot_exe(std::string const & target);

	void displayStatus( void ) const;

private:

	std::string	_name;
	int 		_level;
	int 		_hitPoints;
	int 		_energyPoints;

	// static consts
	static const int _meleeAttackDamage 	= MELEEDAMAGE;
	static const int _rangedAttackDamage 	= RANGEDAMAGE;
	static const int _internetAttackDamage 	= INTERNETDAMAGE;
	static const int _dawnAttackDamage 		= DAWNDAMAGE;
	static const int _victoryAttackDamage 	= VICTORYDAMAGE;
	static const int _armorDamageReduction 	= 5;

	static const int _maxHitPoints 			= 100;
	static const int _maxEnergyPoints 		= 100;
};

#endif
