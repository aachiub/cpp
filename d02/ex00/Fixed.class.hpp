/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 06:17:08 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 08:56:06 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

public:
	Fixed( void );
	Fixed( const Fixed &finit );
	~Fixed( void );

	Fixed& operator = ( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );


private:

	int					_raw;
	static const int	_nbits = 8;

};

#endif