/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:56:08 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 15:17:28 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "span.hpp"

int main( void )
{
    Span sp = Span(5);

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    // try with 10000... and 1 values randomly added to a Span
    std::cout  << std::endl << "* Adding 10000... and 1 random values to a Span using range of iterators" << std::endl;
    int n = 10001;
	std::vector< int > v( n );
    srand( time( NULL ) );
    for( int i = 0; i <= n; i++ )
        v[ i ] = rand() % ( n - 1 );

    Span sp1 = Span( n );
	std::vector< int >::iterator itstart = v.begin();
	std::vector< int >::iterator itend = v.end();

    try {
        sp1.addNumber(itstart, itend);
    }
    catch ( Span::NoWayException( e ) ) {
        std::cout << e.what() << std::endl;
    }    

    std::cout  << std::endl << "* Get shortest and longest Span" << std::endl;
    try {
        std::cout  << "\tShortest span : " << sp1.shortestSpan() << std::endl;
        std::cout  << "\tLongest  span : " << sp1.longestSpan() << std::endl;
    }
    catch ( Span::ImpossibleException( e ) ) {
        std::cout << e.what() << std::endl;
    }    


    // try to add one more value of a full container, should throw am exception
    std::cout  << std::endl << "* Try to add a value to a fully loaded container" << std::endl;
	Span s0 ( 0 );
    try {
        s0.addNumber( 1 );
    }
    catch ( Span::NoWayException( e ) ) {
        std::cout << e.what() << std::endl;
    }    

    // try to add from a range values, should throw am exception
    std::cout  << std::endl << "* Try to add values from a range to a fully loaded container" << std::endl;
    try {
        sp.addNumber(itstart, itend);
    }
    catch ( Span::NoWayException( e ) ) {
        std::cout << e.what() << std::endl;
    }    



    // Spans in an empty ( or 1 lenght ) container
    std::cout  << std::endl << "* Shortest span test on an empty container" << std::endl;
    try {
        std::cout << s0.shortestSpan() << std::endl;
    }
    catch ( Span::ImpossibleException( e ) ) {
        std::cout << e.what() << std::endl;
    }    

    std::cout  << std::endl << "* Longest span test on an empty container" << std::endl;
    try {
        std::cout << s0.longestSpan() << std::endl;
    }
    catch ( Span::ImpossibleException( e ) ) {
        std::cout << e.what() << std::endl;
    }    


    // Span in an 1 lenght container
	Span s1 ( 1 );
    std::cout  << std::endl << "* Sortest span test on a 1 lenght container" << std::endl;
    try {
        std::cout << s1.shortestSpan() << std::endl;
    }
    catch ( Span::ImpossibleException( e ) ) {
        std::cout << e.what() << std::endl;
    }    

    std::cout  << std::endl << "* Longest span test on a 1 lenght container" << std::endl;
    try {
        std::cout << s1.longestSpan() << std::endl;
    }
    catch ( Span::ImpossibleException( e ) ) {
        std::cout << e.what() << std::endl;
    }    

}
