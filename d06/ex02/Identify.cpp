/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:11:49 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 15:59:37 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Classes.hpp"
#include "Identify.hpp"

Identify::Identify( void ) {
    return ;
}

Identify::Identify( Identify const & src ) {
    *this = src;
    return ;
}

Identify::~Identify( void ) {
    return ;
}

Identify & Identify::operator = ( Identify const & rhs ) {
    if ( this != &rhs )
        *this = rhs;
    return ( *this );
}

t_classIndex Identify::byPointer( Base * p )
{
	if ( dynamic_cast< A* >( p ) )
        return ( A_class );

	if ( dynamic_cast< B* >( p ) )
        return ( B_class );
     
	if ( dynamic_cast< C* >( p ) )
        return ( C_class );
     
    return NO_class;
}

t_classIndex Identify::byReference( Base & p )
{
	if (dynamic_cast<A*>( &p ) )
        return ( A_class );

	else if (dynamic_cast< B* >( &p ) )
        return ( B_class );

	else if (dynamic_cast< C* >( &p ) )
        return ( C_class );
     
    return ( NO_class );
}
