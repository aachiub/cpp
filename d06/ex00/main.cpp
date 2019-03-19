/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:17:07 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 23:17:10 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convert.hpp"

int main( int ac, char **av ) {

	if (ac == 2) {
			Convert	convert;
		    std::string strVal( av[ 1 ] );
			convert.toTypes( strVal );
	}
	else {
		std::cout << "usage: " << av[ 0 ] << " <literal_value> - literal_value type can be either char, int, float or double." << std::endl;
		return ( 1 );
	}

	return ( 0 );
}
