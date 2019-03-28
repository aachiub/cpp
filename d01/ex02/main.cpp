/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:17:41 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 14:02:04 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"


int		main( void )
{
	ZombieEvent *ze;

	std::string zTypes[] = {"-10", "-12", "-16", "P", "-18", "-21", "-99" };
	int			nTypes = sizeof(zTypes) / sizeof(zTypes[0]);
	
	/* initialize random seed: */
    srand ( time( NULL ) );
	
	// create Zombie Events,  random value between 1 and 5
    std::cout << "_________________________________________________________________" << std::endl;
    std::cout << "_________________________________________________________________" << std::endl;
	int nze = rand() % 5 + 1; 
	for( int i = 0; i < nze; i++) {

		std::string type = zTypes[  rand() % nTypes ]; // random type
		int nZombies = 5 + rand() %  5; // zombie nb to create : random value between 5 and 9

		// create ZombieEvent instance with random type
		std::cout << OKBLUE << std::endl << "Create ZombieEvent of type (" << \
			WARNING << type << OKBLUE << ") and "<< nZombies << " Zombies with random names" << NORMAL << std::endl;
    //std::cout << "-----------------------------------------------------------------" << std::endl;

		ze = new ZombieEvent();

		ze->setType( type );

		// Create random number of Zombie instances with random names
		for ( int i = 0; i < nZombies; i++)
			ze->RandomChump();
	
		delete ze;
	}
	return 0;
}

