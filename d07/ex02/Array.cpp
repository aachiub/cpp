/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:50:28 by aachir            #+#    #+#             */
/*   Updated: 2019/01/17 20:47:34 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Array.hpp"


int main(void) {

	unsigned int i;
	unsigned int len = 10;


// test with char type

	std::cout << std::endl << "* <char> tpe Array tests";
	// empty array construction, then fill its elements
	std::cout << std::endl << "\tCreate empty array then set its elements values";
	Array<char> cArray1( len );
	// set elements values
	for (i = -1; ++i < cArray1.size(); cArray1[ i ] = 'A' + i );

	std::cout << "\t{ ";
	for (i = 0; i < cArray1.size(); i++)
	{
		std::cout << cArray1[ i ];
		if ( i != len - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


	// copy construction test
	std::cout << std::endl << "\tCopy construction test";
	Array<char> cArray2( cArray1 );

	std::cout << "\t{ ";
	for (i = 0; i < cArray2.size(); i++)
	{
		std::cout << cArray2[ i ];
		if ( i != cArray2.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


	// = Operator test
	std::cout << std::endl << "\tOperator = test ";
	Array<char> cArray3 = cArray2;

	std::cout << "\t{ ";
	for (i = 0; i < cArray3.size(); i++)
	{
		std::cout << cArray3[ i ];
		if ( i != cArray3.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


// test with double type

	std::cout << std::endl << "* <double> tpe Array tests";
	// empty array construction, then fill its elements
	std::cout << std::endl << "\tCreate empty array then set its elements values";
	Array<double> dArray1( len );
	// set elements values
	for (i = -1; ++i < dArray1.size(); dArray1[ i ] = 3.14159 * i );

	std::cout << "\t{ ";
	for (i = 0; i < dArray1.size(); i++)
	{
		std::cout << dArray1[ i ];
		if ( i != dArray1.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


	// copy construction test
	std::cout << std::endl << "\tCopy construction test";
	Array<double> dArray2( dArray1 );

	std::cout << "\t{ ";
	for (i = 0; i < dArray2.size(); i++)
	{
		std::cout << dArray2[ i ];
		if ( i != dArray2.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


	// = Operator test
	std::cout << std::endl << "\tOperator = test ";
	Array<double> dArray3 = dArray2;

	std::cout << "\t{ ";
	for (i = 0; i < dArray3.size(); i++)
	{
		std::cout << dArray3[ i ];
		if ( i != dArray3.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;




// test with string type

	std::cout << std::endl << "* <std::string> tpe Array tests";
	// empty array construction, then fill its elements
	std::cout << std::endl << "\tCreate empty array then set its elements values";
	Array<std::string> sArray1( len );
	// set elements values
	for (i = -1; ++i < sArray1.size(); sArray1[ i ] = "string_" + std::to_string( i ));
	std::cout << "\t{ ";
	for (i = 0; i < sArray1.size(); i++)
	{
		std::cout << sArray1[ i ];
		if ( i != sArray1.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


	// copy construction test
	std::cout << std::endl << "\tCopy construction test";
	Array<std::string> sArray2( sArray1 );

	std::cout << "\t{ ";
	for (i = 0; i < sArray2.size(); i++)
	{
		std::cout << sArray2[ i ];
		if ( i != sArray2.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;


	// = Operator test
	std::cout << std::endl << "\tOperator = test ";
	Array<std::string> sArray3 = sArray2;

	std::cout << "\t{ ";
	for (i = 0; i < sArray3.size(); i++)
	{
		std::cout << sArray3[ i ];
		if ( i != sArray3.size() - 1)
			std::cout << "; ";
	}
	std::cout << " }" << std::endl;

    std::cout << std::endl << std::endl;
}