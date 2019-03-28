/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yellowpages.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:15:51 by aachir            #+#    #+#             */
/*   Updated: 2019/03/25 18:12:19 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "yellowpages.hpp"
#include "Phonebook.class.hpp"

bool isnumber(const std::string &s) {
  return ( !s.empty() && std::all_of( s.begin(), s.end(), ::isdigit ) );
}

bool isprintable(const std::string &s) {
  	for (size_t i = 0; i < s.size(); i++)
		if( s[i] < 32 || s[i] > 127 )
			return ( false );
	return ( true );
}

bool	getContactInfo( std::string const & msg, std::string &info)
{
	std::string	s;

	std::cout << msg << std::endl;
	while ( 1 ) {
		std::cin >> s;
		if ( s == EXIT || std::cin.eof() )
			return ( false );
		if ( isprintable( s ) ) {
			info = s;
			return ( true );
		}
		std::cout << MSGINVALIDENTRY << msg << std::endl;
	}
}

bool	add(Phonebook *pbook)
{
	t_contact	contact;
	std::string	s;
	
	if (pbook->getphonebookcontactnb() == MAXCONTACTS) {
		std::cout << MSGMAXCONTACTS << std::endl;
		return ( false );
	}

	if ( ! getContactInfo( MSGFIRSTNAME, contact.first_name))
		return ( false );
	if ( ! getContactInfo( MSGLASTNAME, contact.last_name))
		return ( false );
	if ( ! getContactInfo( MSGNICKNAME, contact.nick_name))
		return ( false );
	if ( ! getContactInfo( MSGLOGIN, contact.login))
		return ( false );
	if ( ! getContactInfo( MSGPOSTALADDRESS, contact.postal_address))
		return ( false );
	if ( ! getContactInfo( MSGEMAILADDRESS, contact.email_address))
		return ( false );
	if ( ! getContactInfo( MSGPHONENUMBER, contact.phone_number))
		return ( false );
	if ( ! getContactInfo( MSGBIRTHDAYDATE, contact.birthday_date))
		return ( false );
	if ( ! getContactInfo( MSGFAVORITEMEAL, contact.favorite_meal))
		return ( false );
	if ( ! getContactInfo( MSGUNDERWEARCOLOR, contact.underwear_color))
		return ( false );
	if ( ! getContactInfo( MSGDARKESTSECRET, contact.darkest_secret))
		return ( false );

	pbook->addphonebookcontact(&contact);

	std::cout << MSGADDED << std::endl << std::endl;
	return (1);
}

bool	search(Phonebook *pbook)
{
	int 		index;
	int 		nbcontacts;
	int			done;
	t_contact	contact;
	std::string	s;

	if ((nbcontacts = pbook->getphonebookcontactnb()) == 0) {
		std::cout << MSGNOCONTACTS << std::endl  << std::endl;
		return ( false);
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
	std::cout << MSGCONTACTINDEX << std::endl;
	while (!done) {
		std::cin >> s;
		if (std::cin.eof() || s == EXIT)
			return ( false );

		if ( ! isnumber( s )) {
			std::cout << MSGVALIDCONTACTINDEX << std::endl;
			continue ;
		}
		
		index = std::stoi(s) - 1;

		if (pbook->isvalidphonebookcontact(index))
			done = 1;
		else
			std::cout << MSGVALIDCONTACTINDEX << std::endl;
	}

	pbook->getphonebookcontact(index, &contact);

	std::cout << MSGFIRSTNAME << contact.first_name << std::endl;
	std::cout << MSGLASTNAME << contact.last_name << std::endl;
	std::cout << MSGNICKNAME << contact.nick_name << std::endl;
	std::cout << MSGLOGIN << contact.login << std::endl;
	std::cout << MSGPOSTALADDRESS << contact.postal_address << std::endl;
	std::cout << MSGEMAILADDRESS << contact.email_address << std::endl;
	std::cout << MSGBIRTHDAYDATE << contact.phone_number << std::endl;
	std::cout << MSGPHONENUMBER << contact.birthday_date << std::endl;
	std::cout << MSGFAVORITEMEAL << contact.favorite_meal << std::endl;
	std::cout << MSGUNDERWEARCOLOR << contact.underwear_color << std::endl;
	std::cout << MSGDARKESTSECRET << contact.darkest_secret << std::endl;

	return ( true );
}

int		main(void)
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
		if (std::cin.eof() || s == EXIT)
			done = 1;
		else if (s == ADD)
			add(pbook);
		else if (s == SEARCH)
			search(pbook);
		else
			std::cout << MSGVALIDCOMMAND << std::endl;
	}
	delete(pbook);
	return ( 0 );
}