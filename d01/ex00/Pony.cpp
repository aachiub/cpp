/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:52:26 by aachir            #+#    #+#             */
/*   Updated: 2019/03/25 10:44:05 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Pony.hpp"


Pony::Pony(std::string & name, std::string & color, t_gender gender) :
		 			_name( name ), _color( color ), _gender( gender )
{
	std::cout << "Hi, I a " << color << ((_gender == MALE) ? " male" : " female") << " Pony." \
			 << " My name is " << _name << "." << std::endl;

	return ;
}

Pony::Pony(void)
{
	return ;
}

Pony::~Pony(void)
{
	std::cout << "Bye... " << _name << " is leaving now." << std::endl;
	return ;
}

void 		Pony::getname(std::string & name) const
{
	name = this->_name;
}

void 		Pony::setname(std::string & name)
{
	this->_name = name;
}

void		Pony::getcolor(std::string & color) const
{
	color = this->_color;
}

void 		Pony::setcolor(std::string & color)
{
	this->_color = color;
}

t_gender 	Pony::getgender(void) const
{
	return this->_gender;
}

void 		Pony::setgender(t_gender gender)
{
	this->_gender = gender;
}

