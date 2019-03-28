/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:48:03 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 12:55:22 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"


ZombieEvent::ZombieEvent( void ) {
    _type = "No type yet";
    return ;
}

ZombieEvent::ZombieEvent( std::string const & type ) : _type( type ) {
    return ;
}

ZombieEvent::ZombieEvent( ZombieEvent const & src ) {
    *this = src;
    return ;
}

ZombieEvent::~ZombieEvent( void ) {
    return ;
}

ZombieEvent & ZombieEvent::operator = ( ZombieEvent const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

std::string & ZombieEvent::getType( void ) {
    return this->_type;
}

void ZombieEvent::setType( std::string const & type ) {
    this->_type = type;
    return ;
}

void ZombieEvent::RandomChump( void )
{
	std::string zNames[] = {"Freddy", "Gargantua", "The Thing", "The Mommy", "The Exorcist", "Nosferatu", "The Innocent" };

	Zombie	*z = newZombie( zNames[  rand() % sizeof(zNames) / sizeof(zNames[0]) ] );
	z->announce();
	delete z;
}		

Zombie* ZombieEvent::newZombie(std::string name) {
    return ( new Zombie( name, this->_type ) );
}
