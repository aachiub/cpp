/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:07 by aachir            #+#    #+#             */
/*   Updated: 2019/01/09 06:39:10 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

typedef enum 	e_gender {
	MALE 	= 'M',
	FEMALE 	= 'F'
} 				t_gender;

class Pony {

public:
	
	Pony();
	Pony(std::string *name, std::string *color, t_gender gender);
	~Pony(void);

	void 		getname(std::string *name) const;
	void 		setname(std::string *name);
	void		getcolor(std::string *color) const;
	void 		setcolor(std::string *color);
	t_gender	getgender(void) const;
	void 		setgender(t_gender gender);

private:
	std::string	_name;
	std::string	_color;
	t_gender	_gender;

	int			_index;

	static	int	_nbPony;
};

#endif
