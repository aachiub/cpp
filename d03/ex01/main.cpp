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

int main( void ) {

	FragTrap		ft( "Rebel" );
	std::string target = "Solo";

	ft.vaulthunter_dot_exe( target );

	return (0);
}
