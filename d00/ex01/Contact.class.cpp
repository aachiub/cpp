/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:10:11 by aachir            #+#    #+#             */
/*   Updated: 2019/01/08 09:13:15 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>         		// std::string
#include "Contact.class.hpp"

// public member functions

Contact::Contact(t_contact *pcontact) : contact(*pcontact)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::getcontact(t_contact *pcontact) const
{
	*pcontact = this->contact;
}

void 		Contact::setcontact(t_contact *pcontact)
{
	this->contact = *pcontact;
}

// private member functions

std::string *Contact::getfirstname(void) const
{
	return (std::string *)&this->contact.first_name;
}

void		Contact::setfirstname(std::string *firstname)
{
	this->contact.first_name = *firstname;
}

std::string *Contact::getlastname(void) const
{
	return (std::string *)&this->contact.last_name;
}

void 		Contact::setlastname(std::string *lastname)
{
	this->contact.last_name = *lastname;
}

std::string *Contact::getnickname(void) const
{
	return (std::string *)&this->contact.nick_name;
}

void 		Contact::setnickname(std::string *nickname)
{
	this->contact.nick_name = *nickname;
}

std::string *Contact::getlogin(void) const
{
	return (std::string *)&this->contact.login;
}

void 		Contact::setlogin(std::string *login)
{
	this->contact.login = *login;
}

std::string *Contact::getpostaladdress(void) const
{
	return (std::string *)&this->contact.postal_address;
}

void 		Contact::setpostaladdress(std::string *postaladdress)
{
	this->contact.postal_address = *postaladdress;
}

std::string *Contact::getemailaddress(void) const
{
	return (std::string *)&this->contact.email_address;
}

void 		Contact::setemailaddress(std::string *emailaddress)
{
	this->contact.email_address = *emailaddress;
}

std::string *Contact::getphonenumber(void) const
{
	return (std::string *)&this->contact.phone_number;
}

void 		Contact::setphonenumber(std::string *phonenumber)
{
	this->contact.phone_number = *phonenumber;
}

std::string	*Contact::getbirthdaydate(void) const
{
	return (std::string *)&this->contact.birthday_date;
}

void 		Contact::setbirthdaydate(std::string *birthdaydate)
{
	this->contact.birthday_date = *birthdaydate;
}

std::string *Contact::getfavoritemeal(void) const
{
	return (std::string *)&this->contact.favorite_meal;
}

void 		Contact::setfavoritemeal(std::string *favoritemeal)
{
	this->contact.favorite_meal = *favoritemeal;
}

std::string *Contact::getunderwearcolor(void) const
{
	return (std::string *)&this->contact.underwear_color;
}

void 		Contact::setunderwearcolor(std::string *underwearcolor)
{
	this->contact.underwear_color = *underwearcolor;
}

std::string *Contact::getdarkestsecret(void) const
{
	return (std::string *)&this->contact.darkest_secret;
}

void 		Contact::setdarkestsecret(std::string *darkestsecret)
{
	this->contact.darkest_secret = *darkestsecret;
}
