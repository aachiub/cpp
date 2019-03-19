/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:07 by aachir            #+#    #+#             */
/*   Updated: 2019/01/11 22:08:35 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

static FragTrap 	traps[MAXFRAGTRAPS];
static int			nTraps = MAXFRAGTRAPS;
static int 			nbAttacks = MAXATTACKS + 1;
static int			curTarget;

void removeTrap(int index) {
   	traps[ index ] = traps[ nTraps - 1];
	--nTraps;
}

void vaulthunter_dot_exe(std::string const & target) {

	int 		attackAmount, nHunts;
	t_penalty	attackType;
	int 		curHunter;


	if ( !nTraps || !--nbAttacks )
		return ;

	curHunter = lrand48() % nTraps;
	while (curHunter == curTarget )
		curHunter = lrand48() % nTraps;
	
	nHunts = lrand48() % MAXHUMTS;

	while ( --nHunts )
	{	
		if ( !traps[curHunter].setAttackPenalty( VAULT ) && !traps[curHunter].getEnergyPoints() ) {
			removeTrap( curHunter );
			if (!nTraps)
				return ;
			nHunts = 0;
		}
		if ( lrand48() % 2 )
		{
			attackAmount = traps[curHunter].getRangeAttackDamage();
			attackType = RANGE;
			traps[curHunter].rangedAttack( target );
		}
		else
		{
			attackAmount = traps[curHunter].getMeleeAttackDamage();
			attackType = MELEE;
			traps[curHunter].meleeAttack( target );
		}

		traps[curTarget].takeDamage( attackAmount );
		if ( !traps[curTarget].setAttackPenalty(attackType) && !traps[curTarget].getEnergyPoints() ) {
			removeTrap( curTarget );
			if (!nTraps)
				return ;
			nHunts = 0;
		}
	}

	curTarget = lrand48() % nTraps;
	vaulthunter_dot_exe( traps[curTarget].getName() );

	return ;
}

int main( void ) {

	traps[0].setName( "Big Horse" );
	traps[1].setName( "FragTrap Walker" );
	traps[2].setName( "Jolly Jumper" );
	traps[3].setName( "Mickey Mouse" );
	traps[4].setName( "Sitting Bull" );
	traps[5].setName( "Joker" );
	traps[6].setName( "Dingo" );
	traps[7].setName( "Lazy Rabit" );
	traps[8].setName( "Bugs Bunny" );
	traps[9].setName( "Daffy Duck" );

	nbAttacks = MAXATTACKS + 1;
	curTarget = lrand48() % nTraps;

	vaulthunter_dot_exe( traps[curTarget].getName() );
}
