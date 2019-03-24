/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:10:45 by aachir            #+#    #+#             */
/*   Updated: 2019/01/08 09:19:10 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

// public functions 

Phonebook::Phonebook()
{
	this->setphonebookcontactnb(-1);
	return ;
}

Phonebook::~Phonebook(void)
{
	int nb;

	nb = this->getphonebookcontactnb();
	while(--nb >= 0)
		delete(this->contacts[nb]);
	return ;
}

int Phonebook::getphonebookcontactnb(void) const
{
	return this->contactnb + 1;
}

int Phonebook::addphonebookcontact(t_contact *pcontact)
{
	int nb;
	Contact *c;

	if ((nb = this->getphonebookcontactnb()) == MAXCONTACTS)
		return (0);
	if (!(this->contacts[nb] = new Contact(pcontact)))
		return (0);
	++this->contactnb;
	return (1);
}

int	Phonebook::getphonebookcontact(int index, t_contact *pcontact)
{
	if (!this->isvalidphonebookcontact(index))
		return (0);
	this->contacts[index]->getcontact(pcontact);
	return (1);
}

int Phonebook::isvalidphonebookcontact(int index)
{
	return (index >= 0 && index < this->getphonebookcontactnb());
}

// private functions 

int Phonebook::setphonebookcontactnb(int nb)
{
	if (this->isvalidphonebookcontact(nb))
		return (0);
	this->contactnb = nb;
	return (1);
}
