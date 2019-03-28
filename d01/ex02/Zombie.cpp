/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:18:09 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 13:25:54 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"


Zombie::Zombie( void ) : _name("No Name"), _type("No type"){
    return ;
}

Zombie::Zombie( std::string const & name, std::string const & type ) : _name( name ), _type( type ) {
    return ;
}

Zombie::Zombie( Zombie const & src ) {
    *this = src;
    return ;
}

Zombie::~Zombie( void ) {
    return ;
}

Zombie & Zombie::operator = ( Zombie const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

std::string & Zombie::getName( void ) {
    return this->_name;
}

void Zombie::setName( std::string const & name ) {
    this->_name = name;
    return ;
}

std::string & Zombie::getType( void ) {
    return this->_type;
}

void Zombie::setType( std::string const & type ) {
    this->_type = type;
    return ;
}

std::ostream & operator << ( std::ostream  & os, Zombie & rhs  ) {
    return os << "<"  << RED << rhs.getName() << NORMAL << " (Rated: " << WARNING << rhs.getType()<< NORMAL << ")>";
}

void Zombie::announce( void ) {
    std::cout << *this << RED << " That's enough for Bloood !..." << NORMAL << std::endl;
}
