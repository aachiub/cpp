/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:07 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 13:34:58 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

void launchAttack( FragTrap & ft,  std::string & target) {

		std::cout << std::endl;	
		ft.rangedAttack( target );
		ft.takeDamage(20);
		std::cout << std::endl;	

		ft.meleeAttack( target );
		ft.takeDamage(30);
		ft.displayStatus();
		ft.displayStatus();
		std::cout << std::endl;	
}

int main( void ) {

	FragTrap		ft( "Rebel" );
	std::string target = "Solo";
//	launchAttack( ft, target );
	ft.vaulthunter_dot_exe( target );

/*
	FragTrap		ft1( "Warrior" );
	target = "Valiant";
//	launchAttack( ft, target );
	ft.vaulthunter_dot_exe( target );
*/
	return (0);
}
