/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yellowpages.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:38:31 by aachir            #+#    #+#             */
/*   Updated: 2019/01/08 09:13:36 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "yellowpages.hpp"
#include "Phonebook.class.hpp"

int		add(Phonebook *pbook)
{
	t_contact	contact;
	std::string	s;
	
	if (pbook->getphonebookcontactnb() == MAXCONTACTS) {
		std::cout << MSGMAXCONTACTS << std::endl;
		return (0);
	}
	std::cout << MSGFIRSTNAME << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.first_name = s;
	std::cout << MSGLASTNAME << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.last_name = s;
	std::cout << MSGNICKNAME << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.nick_name = s;
	std::cout << MSGLOGIN << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.login = s;
	std::cout << MSGPOSTALADDRESS << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.postal_address = s;
	std::cout << MSGEMAILADDRESS << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.email_address = s;
	std::cout << MSGPHONENUMBER << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.phone_number = s;
	std::cout << MSGBIRTHDAYDATE << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.birthday_date = s;
	std::cout << MSGFAVORITEMEAL << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.favorite_meal = s;
	std::cout << MSGUNDERWEARCOLOR << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.underwear_color = s;
	std::cout << MSGDARKESTSECRET << std::endl;
	std::cin >> s;
	if (s == EXIT)
		return (0);
	contact.darkest_secret = s;
	pbook->addphonebookcontact(&contact);
	std::cout << MSGADDED << std::endl << std::endl;
	return (1);
}

int	search(Phonebook *pbook)
{
	int 		index;
	int 		nbcontacts;
	int			done;
	t_contact	contact;
	std::string	s;

	if ((nbcontacts = pbook->getphonebookcontactnb()) == 0) {
		std::cout << MSGNOCONTACTS << std::endl  << std::endl;
		return (1);
	}
	std::cout << SEARCHTITLE1 << std::endl;
	std::cout << SEARCHTITLE2 << std::endl;
	for (index = 0; index < nbcontacts; ++index) {
		pbook->getphonebookcontact(index, &contact);
		std::cout << std::right << std::setw(10) << index + 1;
		std::cout << COLSEPARATOR;
		s = contact.first_name;
		if (s.length() > 10)
		{
			s.resize(10);
			s[9] = '.';
		}
		std::cout << std::right << std::setw(10) << s;
		std::cout << COLSEPARATOR;
		s = contact.last_name;
		if (s.length() > 10)
		{
			s.resize(10);
			s[9] = '.';
		}
		std::cout << std::right << std::setw(10) << s;
		std::cout << COLSEPARATOR;
		s = contact.nick_name;
		if (s.length() > 10)
		{
			s.resize(10);
			s[9] = '.';
		}
		std::cout << std::right << std::setw(10) << s << std::endl;
	}
	done = 0;
	while (!done) {
		std::cout << MSGENTRYDETAILS << std::endl;
		std::cin >> s;
		if (s == EXIT)
			return (0);
		index = std::stoi(s) - 1;
		if (pbook->isvalidphonebookcontact(index))
			done = 1;
	}
	pbook->getphonebookcontact(index, &contact);
	std::cout << contact.first_name << std::endl;
	std::cout << contact.last_name << std::endl;
	std::cout << contact.nick_name << std::endl;
	std::cout << contact.login << std::endl;
	std::cout << contact.postal_address << std::endl;
	std::cout << contact.email_address << std::endl;
	std::cout << contact.phone_number << std::endl;
	std::cout << contact.birthday_date << std::endl;
	std::cout << contact.favorite_meal << std::endl;
	std::cout << contact.underwear_color << std::endl;
	std::cout << contact.darkest_secret << std::endl;
	return (1);
}

int	main(void)
{
	Phonebook	*pbook;
	int			done;
	std::string	s;

	if (!(pbook = new Phonebook))
		return (1);
	std::cout << MSGWELCOME << std::endl;
	done = 0;
	while (!done) {
		std::cout << MSGENTERCOMMAMD << std::endl;
		std::cin >> s;
		if (s == EXIT)
			done = 1;
		else if (s == ADD)
			add(pbook);
		else if (s == SEARCH)
			search(pbook);
		else
			std::cout << MSGVALIDCOMMAND << std::endl;
	}
	delete(pbook);
	return (0);
}