/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 06:17:02 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 16:11:39 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

Fixed::Fixed( const Fixed &f ) {
	*this = f;
	return ;
}

Fixed::Fixed( void ) {
	this->setRawBits( 0 ); 
	return ;
}

Fixed::Fixed( const int ival ) {
	this->setRawBits( ival * pow( 2, this->_nbits )); 
	return ;
}

Fixed::Fixed( const float fval ) {

	this->setRawBits( roundf( fval * pow( 2, this->_nbits )));
	return ;
}

Fixed::~Fixed( void ) {
	return ;
}

int	Fixed::getRawBits( void ) const {
	return this->_raw; 
}

void Fixed::setRawBits( int const raw ) {
	this->_raw = raw; 
	return ;
}

float Fixed::toFloat(void) const
{
	return roundf( this->_raw) / pow( 2, this->_nbits );
}

int	Fixed::toInt(void) const
{
	return this->_raw / pow( 2, this->_nbits );
}

// assignment operator

Fixed &Fixed::operator = (Fixed const & rhs) {
	this->setRawBits( rhs.getRawBits() );
	return *this;
}

// comparison binary operators

bool Fixed::operator >  ( Fixed const &rhs ) const {
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator <  ( Fixed const &rhs ) const {
	return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator >= ( Fixed const &rhs ) const {
	return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator <= ( Fixed const &rhs ) const {
	return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator == ( Fixed const &rhs ) const {
	return this->toFloat() == rhs.toFloat();
}

bool Fixed::operator != ( Fixed const &rhs ) const {
	return this->toFloat() != rhs.toFloat();
}

// arithmetic binary operators

Fixed  Fixed::operator + ( Fixed const rhs ) const {
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed  Fixed::operator - ( Fixed const rhs ) const {
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed  Fixed::operator * ( Fixed const rhs ) const {
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed  Fixed::operator / ( Fixed const rhs ) const {
	return Fixed( this->toFloat() / rhs.toFloat() );
}

// unary operators

Fixed&  Fixed::operator ++ ( void ) {
	this->setRawBits( this->_raw + 1 + pow( 2, -this->_nbits ));
	return *this;
}

Fixed  Fixed::operator ++ ( const int incr) {
	Fixed tmp = *this;

	// incr and i are unused
	int i = incr;
	i = incr;
	
	++*this;
	return tmp;
}

Fixed&  Fixed::operator -- ( void ) {
	this->setRawBits( this->_raw - 1 - pow( 2, -this->_nbits ));
	return *this;
}

Fixed  Fixed::operator -- ( const int incr) {
	Fixed tmp = *this;

	// incr and i are unused
	int i = incr;
	i = incr;

	--*this;
	return tmp;
}

//  non member operators and functions
 
std::ostream & operator << ( std::ostream & out, Fixed const & rhs )
{
	out << rhs.toFloat();
	return out;
}

Fixed const & Fixed::max ( Fixed & lhs, Fixed & rhs ) {
	return lhs > rhs ? lhs : rhs;
}

Fixed const & Fixed::max ( Fixed const & lhs, Fixed const & rhs ) {
	return lhs > rhs ? lhs : rhs;
}

Fixed const & Fixed::min ( Fixed & lhs, Fixed & rhs ) {
	return lhs < rhs ? lhs : rhs;
}

Fixed const & Fixed::min ( Fixed const & lhs, Fixed const & rhs ) {
	return lhs < rhs ? lhs : rhs;
}

