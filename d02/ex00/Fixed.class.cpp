/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:10:45 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 08:40:36 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.class.hpp"

Fixed::Fixed( const Fixed &finit ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = finit;
}

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0); 
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw; 
}

void	Fixed::setRawBits( int const raw ) {
	this->_raw = raw; 
}

Fixed &Fixed::operator = (Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}
