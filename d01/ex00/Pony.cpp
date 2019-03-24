/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:03 by aachir            #+#    #+#             */
/*   Updated: 2019/01/08 17:20:10 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int	Pony::_nbPony = 0;

Pony::Pony(std::string *name, std::string *color, t_gender gender) :
		 			_name(*name), _color(*color), _gender(gender)
{
	this->_index = Pony::_nbPony;
	++Pony::_nbPony;
}

Pony::Pony(void)
{
	return ;
}

Pony::~Pony(void)
{
	--Pony::_nbPony;
}

void 		Pony::getname(std::string *name) const
{
	*name = this->_name;
}

void 		Pony::setname(std::string *name)
{
	this->_name = *name;
}

void		Pony::getcolor(std::string *color) const
{
	*color = this->_color;
}

void 		Pony::setcolor(std::string *color)
{
	this->_color = *color;
}

t_gender 	Pony::getgender(void) const
{
	return this->_gender;
}

void 		Pony::setgender(t_gender gender)
{
	this->_gender = gender;
}

