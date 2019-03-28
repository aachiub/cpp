/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:19:11 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:04:13 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define OKBLUE      "\033[94m"
#define NORMAL	    "\033[0m"

int		main( void )
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		* brainPtr = &brain;
	std::string		& brainRef = brain;
	
	std::cout << OKBLUE << std::endl << "Display a string by its pointer : " << NORMAL << *brainPtr << std::endl;

	std::cout << OKBLUE << std::endl << "Display a string by its reference : " << NORMAL << brainRef << std::endl;

	return 0;
}

