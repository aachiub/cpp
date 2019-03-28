/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:20 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 16:10:42 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( std::string const & name ) : _name(name) {

	std::cout << BLUE << FRAG4TP << NORMAL;
	std::cout << " Constructor called for " << name << std::endl;

	this->_level = 1;
	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints = this->_maxEnergyPoints;
	
	return ;	
}

ScavTrap::ScavTrap ( void ) {
	std::cout << BLUE << FRAG4TP << NORMAL;
	std::cout << "Default Constructor called" << std::endl;
	
	this->_level = 1;
	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints =  this->_maxEnergyPoints;
	
	return ;	
}

ScavTrap::ScavTrap ( ScavTrap const & src ) {
	
	std::cout << BLUE << FRAG4TP << NORMAL;
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << BLUE << FRAG4TP << NORMAL;
	std::cout << "Destructor called for " << this->getName() << std::endl;
	
	return ;
}

ScavTrap & ScavTrap::operator = ( ScavTrap const & rhs ) {
	
	this->_name = rhs._name;
	this->_level = rhs._level;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	
	return *this;
}

void ScavTrap::setName( std::string const & name ) {
	this->_name = name;
	return ;
}

std::string  ScavTrap::getName( void ) const {
	return this->_name;
}

void ScavTrap::setLevel( int const & level ) {
	this->_level = level;
}

int ScavTrap::getLevel( void ) const {
	return this->_level;
}

void ScavTrap::setHitPoints( int const & hPoints ) {
	this->_hitPoints = hPoints;
}

int ScavTrap::getHitPoints( void ) const {
	return this->_hitPoints;
}

void ScavTrap::setEnergyPoints( int const & ePoints ) {
	this->_energyPoints = ePoints;
}

int ScavTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

void ScavTrap::displayStatus( void ) const {
	std::cout << BLUE << FRAG4TP << NORMAL << "[" << this->getName() << "]";
	std::cout << " status : (Level, " << this->_level << ") (HP, " << this->_hitPoints << ") (EP, " << this->_energyPoints << ")" << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target) {

	std::cout << BLUE << FRAG4TP  << "[" << this->getName() << "]";
	std::cout << " attacks, " << target << " at range, causing " <<  this->_rangedAttackDamage << " points of damage !" << NORMAL << std::endl;

	if ((this->_hitPoints += 10 + rand() % 10) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

void ScavTrap::meleeAttack(std::string const & target) {

	std::cout << BLUE << FRAG4TP << "[" << this->getName() << "]";
	std::cout << " melee attacks, " << target << " causing " <<  this->_meleeAttackDamage <<" points of damage !" << NORMAL << std::endl;

	if ((this->_hitPoints += 10 + rand() % 10) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

void ScavTrap::dawnAttack(std::string const & target) {

	std::cout << BLUE << FRAG4TP << "[" << this->getName() << "]";
	std::cout << " dawn attacks, " << target << " causing " <<  this->_dawnAttackDamage <<" points of damage !" << NORMAL << std::endl;

	if ((this->_hitPoints += 10 + rand() % 10) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

void ScavTrap::internetAttack(std::string const & target) {

	std::cout << BLUE << FRAG4TP << "[" << this->getName() << "]";
	std::cout << " internet attacks, " << target << " causing " <<  this->_internetAttackDamage <<" points of damage !" << NORMAL << std::endl;

	if ((this->_hitPoints += 10 + rand() % 10) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

void ScavTrap::victoryAttack(std::string const & target) {

	std::cout << BLUE << FRAG4TP << "[" << this->getName() << "]";
	std::cout << " victory attacks, " << target << " causing " <<  this->_victoryAttackDamage <<" points of damage !" << NORMAL << std::endl;

	if ((this->_hitPoints += 10 + rand() % 10) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

bool ScavTrap::takePenalty( unsigned int amount ){
	if( !this->getEnergyPoints() )
		return( false );
	
	this->_energyPoints -= amount;
	if ( this->_energyPoints <= 0 ) {
		this->_energyPoints = 0;
		std::cout << BLUE << FRAG4TP << NORMAL << "[" << this->getName() << "]" << RED << MSG_OUTOFENERGY << NORMAL << std::endl;
		return( false );
	}
	return( true );
}

void ScavTrap::beRepaired(unsigned int amount) {

	int hp = this->_hitPoints + amount;
	if ( hp > this->_maxHitPoints )
		amount -= hp - this->_maxHitPoints;

	this->_hitPoints += amount;

	std::cout << BLUE << FRAG4TP << NORMAL << "[" << this->getName() << "]";
	std::cout << " is being repared, costing " << RED <<  amount << NORMAL << " points !" << std::endl;
	
	this->takePenalty( amount - this->_armorDamageReduction );
}

void ScavTrap::takeDamage(unsigned int amount) {

	std::cout << BLUE << FRAG4TP << NORMAL << "[" << this->getName() << "]";
	std::cout << " take damage costing " << RED <<  amount << NORMAL << " points !" << std::endl;

	this->_hitPoints -= amount;
	if ( this->_hitPoints <= 0 )
		this->_hitPoints = 0;

	this->takePenalty( amount );
}

void ScavTrap::vaulthunter_dot_exe(std::string const & target) {
	
	void(ScavTrap::*attackPtr[])(std::string const & ) = { &ScavTrap::meleeAttack, &ScavTrap::rangedAttack, &ScavTrap::internetAttack, \
														&ScavTrap::dawnAttack, &ScavTrap::victoryAttack };
	int nattackPtr = sizeof(attackPtr) / sizeof(attackPtr[0]);
	
	int	damage[] = { this->_meleeAttackDamage, this->_rangedAttackDamage, \
				this->_internetAttackDamage, this->_dawnAttackDamage, this->_victoryAttackDamage };
	
	std::string		Names[] = {"Solo", "Lobster", "Valiant", "Warrior", "Brave"};

	ScavTrap		ft[MAXFRAGTRAPS];
	int				curTarget, nAttacks, curAttack;

	srand( time( NULL ));

	for (int i = 0; i < MAXFRAGTRAPS; i++) {
		ft[i].setName( Names[i] );
		if ( Names[i] == target)
			curTarget = i;
	}

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << BLUE << FRAG4TP << "[" << this->getName() << "]";
	std::cout << " Preparing Vault attack on " << target << NORMAL <<std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	this->displayStatus();
	ft[ curTarget ].displayStatus();
	std::cout << "----------------------------------------------------------------------" << std::endl;

	if ( !this->takePenalty( VAULTPENALTY ))
		return ;

	nAttacks = MAXATTACKS + rand() % MAXATTACKS;
	int nheal = rand() % 3;
	while ( nAttacks-- )
	{	
		if ( !this->takePenalty( 5 + ( rand() % 5 )))
			break;
		
		std::cout << std::endl;
		curAttack = rand() % nattackPtr;
		(this->*attackPtr[curAttack]) ( target );
 
		ft[ curTarget ].takeDamage( damage[ curAttack ] );
 
		if( !--nheal && curAttack % 2 ) {
			ft[ curTarget ].beRepaired( rand() % 50 );
		}

		if( !ft[ curTarget ].getEnergyPoints() )
			break;
	}

	std::cout << "----------------------------------------------------------------------" << std::endl;
	this->displayStatus();
	ft[ curTarget ].displayStatus();
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

