/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:41:29 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:41:06 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Logger.hpp"

Logger::Logger( std::string const & fname ) : _fname( fname ) {
    return ;
}

void    Logger::logToConsole( std::string const & str )  {
    std::cout << str << std::endl;
}

void    Logger::logToFile( std::string const & str )  {

	std::ofstream ofs;
    ofs.open( this->_fname, std::ios_base::app );
	if ( ofs.is_open() ) {
        ofs << str << std::endl;
        ofs.close();
	}
    else
		std::cout << "Fail to open file : " << this->_fname << std::endl;
}

std::string &  Logger::makeLogEntry( std::string const & str ) {
  	time_t		now;
    char		dt[22];
	struct tm	*loctime;
	
  	now = time(NULL);
	loctime = localtime(&now);
	strftime(dt, sizeof(dt), "[%d-%m-%Y %H:%M:%S]", loctime);

    std::stringstream ss;
    ss << dt << " : " << str;
	this->_logEntry = ss.str();

    return ( this->_logEntry );
}

void  Logger::log(std::string const & dest, std::string const & message ) {

    // initializing maber function names array
    std::string fName[] = { "logToConsole", "logToFile" };

    // initializing maber function pointers array
    void ( Logger::*fPtr[] )( std::string const & ) = { &Logger::logToConsole, &Logger::logToFile };
  
    std::string msg = makeLogEntry( message );

	for (int i = 0; i < NFUNC; i++ )
        if ( fName[ i ] == dest ) {
            (this->*fPtr[ i ] )( msg );
            return ;
        }
    std::cout << RED << "Error : " << NORMAL <<  "Logger::" << dest << "(std::string const &) does not exist." << std::endl;
}
