/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:25:07 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 16:12:39 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

void attack( FragTrap & ft, std::string & target )
{

	std::cout << std::endl;	
	ft.rangedAttack( target );
	ft.takeDamage(20);
	std::cout << std::endl;	
	ft.displayStatus();

	std::cout << std::endl;	
	ft.meleeAttack( target );
	ft.takeDamage(30);
	ft.displayStatus();
	std::cout << std::endl;	
}


int main( void ) {

	FragTrap		ft( "Rebel" );
	std::string target = "Solo";

//	attack( ft, target );
	
	ft.vaulthunter_dot_exe( "LEROCK" );

	return (0);
}
