/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:41:19 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:35:09 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>

#define NORMAL	    "\033[0m"
#define RED		    "\033[1;31m"
#define OKBLUE      "\033[94m"

#define NFUNC    2

class Logger {

public:
    Logger( std::string const & fname );

    void    log(std::string const & dest, std::string const & message);

private:
    void            logToConsole( std::string const & str );
    void            logToFile( std::string const & str );
    std::string &   makeLogEntry( std::string const & str );


    std::string     _fname;
    std::string     _logEntry;

};

#endif