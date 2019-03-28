/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:31:31 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 13:47:51 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"


ZombieHorde::ZombieHorde( int N ) : _nZombies ( N ) {
    
    _zombieHorde = new Zombie*[ N ];

	RandomChump( N );

    return ;
}

ZombieHorde::ZombieHorde( ZombieHorde const & src ) {
    *this = src;
    return ;
}

ZombieHorde::~ZombieHorde( void ) {

    for ( int i = 0; i < _nZombies; i++ )
        delete _zombieHorde[ i ];
    delete _zombieHorde; 

    return ;
}

ZombieHorde & ZombieHorde::operator = ( ZombieHorde const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

void ZombieHorde::RandomChump( int nZombies )
{
	std::string zNames[] = {"Freddy", "Gargantua", "The Thing", "The Mommy", "The Exorcist", "Nosferatu", "The Innocent" };
	std::string zTypes[] = {"-10", "-12", "-16", "P", "-18", "-21", "-99" };

	int		nNames = sizeof(zNames) / sizeof(zNames[0]);;
	int     randomIndex;

    /* initialize random seed: */
    srand ( time( NULL ) );

    for ( int i = 0; i < nZombies; i++ ) {
        /* generate random number between 0 and nNames - 1 */
        randomIndex =  rand()  % nNames; 
        _zombieHorde[ i ] = new Zombie( zNames[ randomIndex ], zTypes[ randomIndex ]);
    }
}		

void ZombieHorde::announce() {
    for ( int i = 0; i < _nZombies; i++ )
        _zombieHorde[ i ]->announce();

    return ;
}
