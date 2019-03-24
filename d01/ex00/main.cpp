/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:15:52 by aachir            #+#    #+#             */
/*   Updated: 2019/03/24 14:43:37 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"


void ponyOnTheHeap(void)
{
	std::string 	name;
	std::string 	color;
	Pony			*hPony;


	name 	= "Jolly Jumper";
	color	= "White";
	hPony = new Pony(&name, &color, MALE);

	hPony->getname(&name);
	std::cout << "Pony \""	<< name << "\" has been created on the heap."  << std::endl;

	delete hPony;
}

void	ponyOnTheStack(void)
{
	std::string 	name;
	std::string 	color;
	Pony			sPony;

	name 	= "Sultan";
	sPony.setname(&name);

	color	= "Black";
	sPony.setcolor(&color);

	sPony.setgender(MALE);

	sPony.getname(&name);
	std::cout << "Pony \""	<< name << "\" has been created on the stack."  << std::endl;
}

int		main( void )
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}
