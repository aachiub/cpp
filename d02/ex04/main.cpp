/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 08:14:43 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 10:45:00 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iostream"
#include "EvalExpr.hpp"

int main( int ac, char **av) {

	if ( ac != 2) {
		std::cout << "usage: " << av[0] << " \"<arihmetic_expression>\"" << std::endl \
					<< "\tExample:  " <<  av[0] << " \"( 3  * ( 2 + 4 ))\"" << std::endl; 
		return ( 1 );
	}
	
	std::string str( av[1] );	
	Expression expr( str );

	if ( expr. analyse() )
		if ( expr.compute() )  { 
			std::cout << expr.getResult() << std::endl;
			return ( 0 );
		}
	return ( 1 );
}
