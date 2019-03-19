/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:49:00 by aachir            #+#    #+#             */
/*   Updated: 2019/01/08 09:16:31 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTCLASS_HPP
# define CONTACTCLASS_HPP

#include <iostream>

typedef struct s_contact {
	std::string 	first_name;
	std::string 	last_name;
	std::string 	nick_name;
	std::string 	login;
	std::string		postal_address;
	std::string		email_address;
	std::string		phone_number;
	std::string		birthday_date;
	std::string		favorite_meal;
	std::string		underwear_color;
	std::string		darkest_secret;
} t_contact;

class Contact {

public:
	Contact(t_contact * pcontact);
	~Contact(void);

	void		getcontact(t_contact *pcontact) const;
	void 		setcontact(t_contact *pcontact);

private:

	t_contact contact;

	std::string *getfirstname(void) const;
	void 		setfirstname(std::string *firstname);
	std::string *getlastname(void) const;
	void 		setlastname(std::string *lastname);
	std::string *getnickname(void) const;
	void 		setnickname(std::string *nickname);
	std::string *getlogin(void) const;
	void 		setlogin(std::string *login);
	std::string *getpostaladdress(void) const;
	void 		setpostaladdress(std::string *postaladdress);
	std::string *getemailaddress(void) const;
	void 		setemailaddress(std::string *emailaddress);
	std::string	*getbirthdaydate(void) const;
	void 		setbirthdaydate(std::string *birthdaydate);
	std::string *getphonenumber(void) const;
	void 		setphonenumber(std::string *phonenumber);
	std::string *getfavoritemeal(void) const;
	void 		setfavoritemeal(std::string *favoritemeal);
	std::string *getunderwearcolor(void) const;
	void 		setunderwearcolor(std::string *underwearcolor);
	std::string *getdarkestsecret(void) const;
	void 		setdarkestsecret(std::string *darkestsecret);

};

#endif
