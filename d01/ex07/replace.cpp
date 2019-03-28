/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 08:52:54 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 10:02:50 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fstream>
#include <iostream>

bool	replace( std::string const & file_in, std::string const & s1, std::string const & s2) {

	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open( file_in );
	if ( !ifs.is_open() ) {
		std::cout << "Fail to open file : " << file_in << std::endl;
		return ( false );
	}

	std::string	file_out = file_in + ".replace";
	ofs.open( file_out );
	if ( !ofs.is_open() ) {
		std::cout << "Fail to open file : " << file_out << std::endl;
		return ( false );
	}

	std::string line;

	bool firstline = true;
	size_t foundpos;
	while ( std::getline(ifs, line) ) {
		if ( s1 != s2 )
			while ( ( foundpos = line.find( s1 ) ) != std::string::npos )
				line.replace( line.begin() + foundpos, line.begin() + foundpos + s1.size(), s2 );

		if ( !firstline )
			ofs << std::endl;

		ofs << line;
		firstline = false;
	}

	ofs.close();
	ifs.close();
	return ( true );
}

int		main( int ac, char ** av ) {

	if ( ac != 4) {
		std::cout << "usage: " << av[0] << " <filname> \"string1\"  \"string2\"" << std::endl;
		return ( 1 );
	}

	return ( !replace( av[ 1 ], av[ 2 ], av[ 3 ]) );
}

