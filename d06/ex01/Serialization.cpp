/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:11:49 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 20:06:32 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization( void ) {
	return ;
}

Serialization::Serialization( Serialization const & src ) {
    *this = src;
    return ;
}

Serialization::~Serialization( void ) { return ; }

Serialization & Serialization::operator = ( Serialization const & rhs ) {
    if ( this != &rhs )
        *this = rhs;
    return *this;
}


void * Serialization::serialize( void )
{
	char	alphaNumTab[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	srand( time( NULL ) );

	DataOnHeap *pData = new DataOnHeap;
	// n setting
	pData->n = rand();

	// s1 and s2 setting
	size_t mod = sizeof( alphaNumTab ) - 1;
    int i = -1;
	while ( ++i < NBALPHANUM )
	{
		pData->s1[ i ] = alphaNumTab[ rand() % mod ];
		pData->s2[ i ] = alphaNumTab[ rand() % mod ];
	}
    return ( reinterpret_cast<void*>( pData ) );
}

Data * Serialization::deserialize( void * raw )
{
	char	*s = reinterpret_cast<char*>( raw );

	Data	*pData = new Data;

	// s1 setting
	pData->s1 = std::string( s );
	pData->s1.resize( NBALPHANUM );

	// n setting
	pData->n = *reinterpret_cast<int*>( s += NBALPHANUM );

	// s2 setting
	pData->s2 = std::string( s + sizeof( int ) );
	pData->s2.resize( NBALPHANUM );

	return pData;
}
