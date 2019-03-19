/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:55:09 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 11:12:44 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void) {

    int i;
    std::vector<int> v( 10 );

    // initialize container with int values from 1 to 10
    std::cout << std::endl << "* Initialize container with int values from 1 to 10 : { ";
    for( i = -1; ++i < 10; v[ i ] = i + 1 );


    for( i = 0; i < 10; i++ ) {
        std::cout << i;
        if ( i < 9)
            std::cout << ", ";
    }
    std::cout << " } " << std::endl << std::endl << "* Search for int values from -1 to 11:" << std::endl;

    // search for int values from -1 to 11
    for( i = -1; i < 12; i++ ) {
        std::cout<< "\tSearch for : " << i << "\t";
        if ( easyfind< std::vector <int> >( v, i ) )
            std::cout << "Found" << std::endl;
        else
            std::cout << "\033[1;31mNot found !\033[0m" << std::endl;
    }
    
    return (0);
}
