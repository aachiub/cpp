/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:42:11 by aachir            #+#    #+#             */
/*   Updated: 2019/01/17 20:46:52 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iomanip>

template <typename T>
class Array {

public:
    Array<T> ( void ) { this->_array = NULL;	this->_size = 0; }

    Array<T> ( unsigned int & len ) { this->_array = new T[ len ]();  this->_size = len; }

    Array<T> ( Array<T> & src ) { this->_array = new T[ src.size() ]();	this->_size = src.size();
								for ( unsigned int i = -1; ++i < this->_size; this->_array[ i ] = src[ i ] );}

    ~Array<T> ( void ) { }

    Array<T> & operator = ( Array<T> const & rhs ) { if ( this->_array ) delete this->_array;	this->_array = new T[ rhs.size() ]();
		  						for ( unsigned int i = -1; ++i < this->_size; this->_array[ i ] = rhs[ i ] );
		  						this->_size = rhs.size();	return *this->_array; }

    unsigned int & size( void )  {	return this->_size; }

	T & operator [] ( unsigned int const idx ) { if ( idx < 0 || idx >= this->_size ) throw std::exception();
												return this->_array[ idx ]; }

private:

    T *		     	_array;
	unsigned int	_size;

};

#endif
