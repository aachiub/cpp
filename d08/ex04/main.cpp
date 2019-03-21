/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:31:24 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 23:20:27 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "EvalExpr.hpp"

int main( int ac, char **av) {

	if ( ac != 2) {
		std::cout << "usage: " << av[0] << " \"<arihmetic_expression>\"" << std::endl \
					<< "\tExample:  " <<  av[0] << " \"3 + ((1 + 4) * 2) - 1\"" << std::endl; 
		return ( 1 );
	}
	
	std::string str( av[1] );	
	Expression expr( str );

	if ( expr. analyse() )
		if ( expr.evaluate() ) { 
			std::cout << "Result : " << expr.getResult() << std::endl;
			return ( 0 );
		}
	return ( 1 );
}