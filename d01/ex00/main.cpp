/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:51:50 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 14:59:04 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"


#define OKBLUE      "\033[94m"
#define NORMAL	    "\033[0m"

void ponyOnTheHeap(void)
{
	std::string 	name;
	std::string 	color;


	name 	= "Jolly Jumper";
	color	= "White";
	std::cout << OKBLUE << std::endl << "Creating a pony on the heap ..." << NORMAL << std::endl;
	Pony *heapPony = new Pony( name, color, MALE);
	delete heapPony;
}

void	ponyOnTheStack(void)
{
	std::string 	name;
	std::string 	color;

	name 	= "Sultan";
	color	= "Black";
	std::cout << OKBLUE << std::endl << "Creating a pony on the stack ..." << NORMAL << std::endl;
	Pony stackPony(  name, color, MALE);
}

int		main( void )
{

	ponyOnTheHeap();
	
	ponyOnTheStack();

	return 0;
}
