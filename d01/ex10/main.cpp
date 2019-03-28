/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:52:56 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 14:53:11 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

bool	catStandardInput( void ) {
	std::string line;

	while (std::cin) {
		getline(std::cin, line);
		std::cout << line << std::endl;
	}
	return ( true );
}

bool	catFile( std::string const & file_in ) {

	std::ifstream ifs( file_in );
	if ( !ifs.is_open() ) {
		std::cout << "Fail to open file : " << file_in << std::endl;
		return ( false );
	}

	std::string line;

	bool firstline = true;
	while ( std::getline(ifs, line) ) {
		if ( !firstline )
			std::cout << std::endl;
		std::cout << line;
		firstline = false;
	}

	ifs.close();
	return ( true );
}

int		main( int ac, char ** av ) {
	bool ret = true;

	if ( ac == 1 || *av[1] == '-')
		return ( !catStandardInput() );

	for (int i = 1; i <= ac; i++)
		ret &= catFile( av[ i ] );
	
	return ( !ret );
}

