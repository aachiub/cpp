/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:11:09 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 08:40:58 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath> 
#include "Fixed.class.hpp"

Fixed::Fixed( const Fixed &f ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	setRawBits( 0 ); 
}

Fixed::Fixed( const int ival ) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits( ival * pow( 2, this->_nbits )); 
}

Fixed::Fixed( const float fval ) {
	std::cout << "float constructor called" << std::endl;

	setRawBits( roundf( fval * pow( 2, this->_nbits )));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw; 
}

void Fixed::setRawBits( int const raw ) {
	this->_raw = raw; 
}

float Fixed::toFloat(void) const
{
	return roundf(this->_raw) / pow( 2, this->_nbits );
}

int	Fixed::toInt(void) const
{
	return this->_raw / pow( 2, this->_nbits );
}

Fixed & Fixed::operator = (Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(rhs._raw);
	return *this;
}

// non member functions

std::ostream & operator << ( std::ostream & out, Fixed const & rhs )
{
	out << rhs.toFloat();
	return out;
}

