/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 06:17:08 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 15:52:21 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:
	Fixed( void );
	Fixed( const Fixed &finit );
	~Fixed( void );

	Fixed( const int ival );
	Fixed( const float fval );


	int		getRawBits( void ) const;
	void	setRawBits( int const raw );


	float	toFloat( void ) const;
	int		toInt( void ) const;
	
// assignment operator
	Fixed& operator = ( Fixed const & rhs );

// comparison binary operators
	bool operator  >  ( Fixed const &rhs ) const;
	bool operator  <  ( Fixed const &rhs ) const;
	bool operator  >= ( Fixed const &rhs ) const;
	bool operator  <= ( Fixed const &rhs ) const;
	bool operator  == ( Fixed const &rhs ) const;
	bool operator  != ( Fixed const &rhs ) const;

// arithmetic binary operators
	Fixed  operator + ( Fixed const rhs ) const;
	Fixed  operator - ( Fixed const rhs ) const;
	Fixed  operator * ( Fixed const rhs ) const;
	Fixed  operator / ( Fixed const rhs ) const;

// unary operators
	Fixed& operator ++ ( void );			// prefix increment
	Fixed  operator ++ ( const int incr );	// postfix increment
	Fixed& operator -- ( void );			// prefix decrement
	Fixed  operator -- ( const int incr );	// postfix decrement


//  static functions
	static Fixed const & max ( Fixed & lhs, Fixed & rhs );
	static Fixed const & max ( Fixed const &lhs, Fixed const & rhs );
	static Fixed const & min ( Fixed & lhs, Fixed & rhs );
	static Fixed const & min ( Fixed const & lhs, Fixed const & rhs );

private:

	int					_raw;
	static const int	_nbits = 8;

};

//  non member operators and functions

std::ostream & operator << ( std::ostream & out, Fixed const & rhs );

#endif