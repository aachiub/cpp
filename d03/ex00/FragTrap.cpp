/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:20 by aachir            #+#    #+#             */
/*   Updated: 2019/01/11 21:43:19 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap ( std::string const & name ) : _name(name) {
	std::cout << TXTBLUE << FRAG4TP  << " Constructor called for " << name << TXTNORMAL << std::endl;
	this->_level = 1;
	this->_hitPoints = _maxHitPoints;
	this->_energyPoints = _maxEnergyPoints;
	return ;	
}

FragTrap::FragTrap ( void ) {
	std::cout << TXTBLUE << FRAG4TP << "Default Constructor called" << TXTNORMAL << std::endl;
	this->_level = 1;
	this->_hitPoints = _maxHitPoints;
	this->_energyPoints = _maxEnergyPoints;
	return ;	
}

FragTrap::FragTrap ( FragTrap const & src ) {
	std::cout << TXTBLUE << FRAG4TP << "Copy constructor called"  << TXTNORMAL << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap( void ) {
	std::cout << TXTBLUE << FRAG4TP << "Destructor called for " << this->getName() << TXTNORMAL << std::endl;
	return ;
}

FragTrap & FragTrap::operator = ( FragTrap const & rhs ) {
	this->_name = rhs._name;
	this->_level = rhs._level;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	return *this;
}

void FragTrap::setName( std::string const & name ) {
	this->_name = name;
	return ;
}

std::string  FragTrap::getName( void ) const {
	return this->_name;
}

void FragTrap::setLevel( int const & level ) {
	this->_level = level;
}

int FragTrap::getLevel( void ) const {
	return this->_level;
}

void FragTrap::setHitPoints( int const & hPoints ) {
	this->_hitPoints = hPoints;
}

int FragTrap::getHitPoints( void ) const {
	return this->_hitPoints;
}

void FragTrap::setEnergyPoints( int const & ePoints ) {
	this->_energyPoints = ePoints;
}

int FragTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

int FragTrap::getRangeAttackDamage( void ) const {
	return this->_rangedAttackDamage;
}

int	FragTrap::getMeleeAttackDamage( void ) const {
	return this->_meleeAttackDamage;
}

bool FragTrap::setAttackPenalty( t_penalty const & type ) {
	
	int amount;
	std::string msg;

	if ( type == VAULT ) {
		amount = VAULTPENALTY;
		msg = MSG_VAULTATTACK;
	}
	else if ( type == MELEE ) {
		amount = this->_meleeAttackDamage;
		msg = MSG_MELEEATTACK;
	}
	else if ( type == RANGE ) {
		amount = this->_rangedAttackDamage;
		msg = MSG_RANGEATTACK;
	}
	else if ( type == ARMOR ) {
		amount = this->_armorDamageReduction;
		msg = MSG_ARMORDAMAGE;
	}
	else
		return false;

	this->_energyPoints -= amount;
	if (this->_energyPoints <= 0 ) {
		this->_energyPoints = 0;
		std::cout << TXTBLUE << FRAG4TP << TXTYELLOW << this->getName() << msg \
					<< TXTRED << MSG_OUTOFENERGY << this->getName() << '!'<< TXTNORMAL << std::endl;
		return false ;
	}
//	else
//		std::cout << TXTNORMAL  << "\t ... " << msg << std::endl;


	return true;

}

void FragTrap::rangedAttack(std::string const & target) {

	std::cout << TXTBLUE << FRAG4TP << TXTGREEN << this->_name << TXTNORMAL << " attacks, " << TXTRED  << target \
				<< TXTNORMAL << " at range, causing " << TXTRED <<  this->_rangedAttackDamage << TXTNORMAL \
				<<" points of damage !" << TXTNORMAL << std::endl;

	if ((this->_hitPoints += _rangedAttackDamage) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

void FragTrap::meleeAttack(std::string const & target) {

	std::cout << TXTBLUE << FRAG4TP << TXTGREEN << this->_name << TXTNORMAL << " melee attacks, " << TXTRED << target\
				 << TXTNORMAL << " causing " << TXTRED <<  this->_meleeAttackDamage << TXTNORMAL \
				 <<" points of damage !" << TXTNORMAL << std::endl;

	if ((this->_hitPoints += _meleeAttackDamage) > _maxHitPoints)
		this->_hitPoints =_maxHitPoints ;

	return ;	
}

void FragTrap::takeDamage(unsigned int amount) {

	std::cout << TXTBLUE << FRAG4TP << TXTRED << this->_name << TXTNORMAL << " take damage costing " \
				 << TXTRED <<  amount << TXTNORMAL << " points !" << std::endl;

	this->beRepaired( this->_armorDamageReduction );
	return ;
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << TXTBLUE << FRAG4TP << TXTYELLOW << this->_name << TXTNORMAL << " needs repairs costing " \
				 << TXTRED <<  amount << TXTNORMAL << " points !" << TXTNORMAL << std::endl;

	this->setAttackPenalty(ARMOR);

	return ;	
}
