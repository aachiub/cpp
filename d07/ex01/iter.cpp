/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:44:21 by aachir            #+#    #+#             */
/*   Updated: 2019/01/17 15:26:53 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


template <typename T>
void iter (T * pArray, size_t const len, void ( * f )( T & ) ) {
	for (size_t i = 0; i < len; i++)
		if ( f )
			f( pArray[ i ]);
		else
			std::cout << "  " << pArray[ i ];
	return ;
}

template <typename T>
void printElem (T & elem ) {
	std::cout << "  " << elem;
	return ;
}

int main(void) {

	char charTab[] = { 'A', 'a', 'c', 'h', 'i', 'r' };
    std::cout << std::endl << "* Iter test with <char> array" << std::endl;
	::iter<char>( charTab, sizeof( charTab )  / sizeof( char ) , NULL );
    std::cout << std::endl << "* Iter test with <char> array with an instantiated function template" << std::endl;
	::iter<char>( charTab, sizeof( charTab )  / sizeof( char ) , &::printElem< char > );

	int intTab[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << std::endl << std::endl << "* Iter test with <int> array" << std::endl;
	::iter< int >( intTab, sizeof( intTab ) / sizeof( int ), &::printElem< int > );
    std::cout << std::endl << "* Iter test with <int> array with an instantiated function template" << std::endl;
	::iter< int >( intTab, sizeof( intTab ) / sizeof( int ), &::printElem< int > );

	float floatTab[] = { 210.12f, 321.23f, 432.34f, 543.45f, 3.141592653589793f };
    std::cout << std::endl << std::endl << "* Iter test with <float> array" << std::endl;
	::iter< float >( floatTab, sizeof( floatTab ) / sizeof( float ), NULL );
    std::cout << std::endl << "* Iter test with <float> array with an instantiated function template" << std::endl;
	::iter< float >( floatTab, sizeof( floatTab ) / sizeof( float ), &::printElem< float > );


	std::cout.precision(15);
	double doubleTab[] = { 3210.123, 4321.234, 5432.345, 3.456, 3.141592653589793  };
    std::cout << std::endl << std::endl  << "* Iter test with <double> array" << std::endl;
	::iter< double >( doubleTab, sizeof( doubleTab ) / sizeof( double ), NULL );
    std::cout << std::endl << "* Iter test with <double> array with an instantiated function template" << std::endl;
	::iter< double >( doubleTab, sizeof( doubleTab ) / sizeof( double ), &::printElem< double > );

	std::string stringTab[] = { "Bonjour", "les", "gens" };
    std::cout << std::endl << std::endl  << "* Iter test with <string> array" << std::endl;
	::iter< std::string >( stringTab, sizeof( stringTab ) / sizeof (std::string), NULL );
    std::cout << std::endl << "* Iter test with <string> array with an instantiated function template" << std::endl;
	::iter< std::string >( stringTab, sizeof( stringTab ) / sizeof (std::string), &::printElem< std::string > );

    std::cout << std::endl << std::endl;
}