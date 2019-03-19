/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:56:17 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 12:49:35 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <vector>

class Span {
public:

    Span( unsigned int size );
    ~Span( void );
    Span( Span const & src );

    Span & operator = ( Span const &rhs );

    void addNumber( int value );
    void addNumber( std::vector< int >::iterator itstart, std::vector< int >::iterator itend );

    int	shortestSpan( void );
    int	longestSpan( void );


    // Exceptions handling classes
    class NoWayException : public std::exception {
        public:
            NoWayException( void );
            NoWayException( NoWayException const & e );
            ~NoWayException( void ) throw();

            NoWayException & operator = ( NoWayException const & rhs );

            virtual const char * what() const throw();
    };
    class ImpossibleException : public std::exception {
        public:
            ImpossibleException( void );
            ImpossibleException( ImpossibleException const & e );
            ~ImpossibleException( void ) throw();

            ImpossibleException & operator = ( ImpossibleException const & rhs );

            virtual const char * what() const throw();
    };


private:
    std::vector<int>		_container;
    unsigned int			_len;

};

#endif
