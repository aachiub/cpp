/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:11:32 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 16:00:17 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Classes.hpp"

A::A ( void ) {
	std::cout << std::endl << "* Class A instance randomly generated" << std::endl;
    return ;
}

A::A ( A const & src ) {
    *this = src;
    return ;
}

A::~A ( void ) {
    return ;
}

A & A::operator = ( A const & rhs ) {
    if ( this != &rhs )
        *this = rhs;
    return ( *this );
}


B::B( void ) {
	std::cout << std::endl << "* Class B instance randomly generated" << std::endl;
    return ;
}


B::B( B const & src ) {
    *this = src;
    return ;
}

B::~B( void ) {
    return ;
}

B & B::operator = ( B const & rhs ) {
    if ( this != &rhs )
        *this = rhs;
    return ( *this );
}

C::C( void ) {
	std::cout << std::endl << "* Class C instance randomly generated" << std::endl;
    return ;
}


C::C( C const & src ) {
    *this = src;
    return ;
}

C::~C( void ) {
    return ;
}

C & C::operator = ( C const & rhs ) {
    if ( this != &rhs )
        *this = rhs;
    return ( *this );
}
