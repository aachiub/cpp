/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:16:02 by aachir            #+#    #+#             */
/*   Updated: 2019/03/25 18:12:14 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

#include "Contact.class.hpp"

# define MAXCONTACTS	8

class Phonebook {

public:

	Phonebook();
	~Phonebook(void);

	int	addphonebookcontact(t_contact *contact);
	int	getphonebookcontact(int index, t_contact	*contact);
	int getphonebookcontactnb(void) const;
	int isvalidphonebookcontact(int nb);

private:
	Contact		*contacts[MAXCONTACTS];
	int			contactnb;

	int setphonebookcontactnb(int nb);
};

#endif
