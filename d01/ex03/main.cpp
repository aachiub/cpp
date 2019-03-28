/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:17:41 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 13:31:36 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "ZombieHorde.hpp"


int		main( void )
{
	/* initialize random seed: */
    srand ( time( NULL ) );

  	/* create a Zombie horde with generated random number between 5 and 10 */
    std::cout << std::endl << OKBLUE << "Create a Zombie horde with generated random zombie number between 5 and 9 " << NORMAL << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;
	
	int N = rand() % 5 + 5;
	
	ZombieHorde zh( N );

	zh.announce();

	return 0;
}

