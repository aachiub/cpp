/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:56:13 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 15:12:48 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <iostream>
#include "span.hpp"

Span::Span( unsigned int size ): _container( size ), _len( 0 ) {
    return ;
}

Span::Span( Span const & src ) {
	*this = src;
    return ;
}

Span::~Span(void) {
    return ;
}

Span & Span::operator = ( Span const & rhs ) {
	this->_container = rhs._container;
	return (*this);
}

void Span::addNumber( int value ) {

	if (this->_len == this->_container.size() )
		throw ( Span::NoWayException() );

	this->_container[ this->_len++ ] = value;
}

void Span::addNumber( std::vector< int >::iterator itstart, std::vector< int >::iterator itend ) {
  
    unsigned int roomLeft =  this->_container.size() - this->_len;
    if ( roomLeft < std::distance( itstart, itend ) )
		throw ( Span::NoWayException() );

	for ( ; itstart != itend; this->_container[ this->_len++ ] = *itstart++ );
}

int	Span::shortestSpan(void) {
	
	if (this->_len <= 1 )
		throw ( Span::ImpossibleException() );

	std::vector< int >::iterator it = this->_container.begin();
	int shortestSpan = abs( *it - *( it + 1 ) );
	
	for ( ; it != this->_container.end() - 1; it++ )
		if ( abs( *it - *( it + 1) ) < shortestSpan )
			shortestSpan = abs( *it - *(it + 1) );

	return ( shortestSpan );
}

int	Span::longestSpan(void) {
	if ( this->_len <= 1 )
		throw ( Span::ImpossibleException() );

	std::vector< int >::iterator it = this->_container.begin();
	int longestSpan = 0 ;
	
	for ( ; it != this->_container.end() - 1; it++ )
		if ( abs( *it - *( it + 1) ) > longestSpan )
			longestSpan = abs( *it - *(it + 1) );

	return ( longestSpan );
}



// exceptions handling classes functions

// NoWayException
Span::NoWayException::NoWayException( void ) {
    return ;
}

Span::NoWayException::NoWayException( NoWayException  const & e ) {
    *this = e;
    return ;
}

Span::NoWayException::~NoWayException( void ) throw() {
    return ;
}

Span::NoWayException & Span::NoWayException::operator = ( NoWayException const & rhs ) {
    std::string unused = rhs.what();
    return *this;
}

const char * Span::NoWayException::what() const throw() {
    return ( "\033[1;31mSpan is fully loaded !\033[0m");
}


// ImpossibleException
Span::ImpossibleException::ImpossibleException( void ) {
    return ;
}

Span::ImpossibleException::ImpossibleException( ImpossibleException const & e ) {
    *this = e;
    return ;
}

Span::ImpossibleException::~ImpossibleException( void ) throw() {
    return ;
}

Span::ImpossibleException & Span::ImpossibleException::operator = ( ImpossibleException const & rhs ) {
    std::string unused = rhs.what();
    return *this;
}

const char * Span::ImpossibleException::what() const throw() {
    return ("\033[1;31mSpan must contain at least 2 values !\033[0m");
}
