/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:12:04 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 15:51:51 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Identify.hpp"
#include "Classes.hpp"

int	main( void )
{
	Base *pBase;

	srand( time( NULL ) );

	int n = rand() % 3;

	if ( n == A_class )
		pBase = reinterpret_cast< Base* > ( new A );
	else if (n == B_class)
		pBase = reinterpret_cast< Base* > ( new B );
	else //c_class
		pBase = reinterpret_cast< Base* > ( new C );

	if ( !pBase )
		return ( 1 );

	Identify ident;

	n = ident.byPointer( pBase );
	std::cout << " --> Class " << (( n == A_class ) ? "A" : ( n == B_class ) ? "B" : ( n == C_class ) ? "C" : "Unknown" ) \
							 << " instance pointer." << std::endl;

	n = ident.byReference( *pBase );
	std::cout << " --> Class " << (( n == A_class ) ? "A " : ( n == B_class ) ? "B" : ( n == C_class ) ? "C" : "Unknown" ) \
							 << " instance reference." << std::endl;

	delete pBase;
}