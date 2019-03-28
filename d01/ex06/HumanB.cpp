/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 08:10:39 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:12:24 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string const & name ) : _name( name ) {
    return ;
}

HumanB::~HumanB( void ) {
    return ;
}

void HumanB::setWeapon( Weapon & weapon )  {
    this->_weapon = &weapon;
}

void HumanB::attack( void ) {
    std::cout << std::endl << RED << ")--> " << ENDC << _name << " attacks using " << _weapon->getType() << std::endl;
}
