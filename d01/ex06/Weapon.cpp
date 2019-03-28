
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coplien.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:14:42 by aachir            #+#    #+#             */
/*   Updated: 2019/03/25 16:18:16 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "Weapon.hpp"


Weapon::Weapon( std::string const & type ) : _type( type ) {
    return ;
}

Weapon::~Weapon( void ) {
    return ;
}

std::string const & Weapon::getType( void )  {
    return this->_type;
}

void Weapon::setType( std::string const & type )  {
    this->_type = type;
    return ;
}

