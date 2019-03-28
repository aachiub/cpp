/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:53:27 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:39:41 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main() {
    Logger  lg( "Logger.txt" );

    std::cout << std::endl << OKBLUE << "logging to console ..." << NORMAL << std::endl;
    lg.log("logToConsole", "I am logging to console");

    std::cout << std::endl << OKBLUE << "logging to Logger.txt ..." << NORMAL << "\n... (see logger.txt)" << std::endl;
    lg.log("logToFile", "I am logging to Logger.txt");
    
    std::cout << std::endl << OKBLUE << "logging to a fake device : Its_A_Joke ..." << NORMAL << std::endl;
    lg.log("Its_A_Joke", "I am logging to a nothing");

}