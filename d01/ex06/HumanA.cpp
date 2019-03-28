/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 08:10:28 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:12:19 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( std::string const & name, Weapon & weapon ) : _name(name), _weapon (weapon) {
    return ;
}

HumanA::~HumanA( void ) {
    return ;
}

void HumanA::attack( void ) {
    std::cout << std::endl << RED << ")--> " << ENDC << _name << " attacks using " << _weapon.getType() << std::endl;
}

