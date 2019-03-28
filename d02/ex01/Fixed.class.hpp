/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:11:19 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 08:41:02 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> 

class Fixed {

public:
	Fixed( void );
	Fixed( const Fixed &finit );
	Fixed( const int ival );
	Fixed( const float fval );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	Fixed & operator = ( Fixed const & rhs );

private:

	int					_raw;
	static const int	_nbits = 8;

};

// non member functions

std::ostream & operator << ( std::ostream & out, Fixed const & rhs );

#endif