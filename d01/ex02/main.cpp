/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:15:52 by aachir            #+#    #+#             */
/*   Updated: 2019/03/24 14:43:37 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"


int RandomChump( int nb)
{
  	/* generate random number between 0 and nb - 1 */
  	return rand() % nb;
}		

int		main( void )
{
	std::string Znames[] = {"Freddy", "Gargantua", "The Thing", "Halloween Master", "The Exorcist", "Nosferatu", "The Innocent" };
	std::string Ztypes[] = {"Bad", "Ugly", "Very mean", "Horrifying", "One eyed", "Saw handed", "Monster Master" };
	int			nzombies = sizeof(Znames) / sizeof(Znames[0]);;
	Zombie 		*z;

	/* initialize random seed: */
    srand ( time( NULL ) );

	ZombieEvent ze( Ztypes[  RandomChump ( nzombies ) ] );
	for ( int i = 0; i < nzombies; i++) {
		z = ze.newZombie( Znames[  RandomChump ( nzombies ) ] );
		z->announce();
		ze.setType( Ztypes[  RandomChump ( nzombies ) ] );
		delete z;
	}
	return 0;
}
