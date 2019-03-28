/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:06:46 by aachir            #+#    #+#             */
/*   Updated: 2019/03/25 18:11:44 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
 	std::string str;
	int			i;
 
	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			str = av[i];
			for (std::string::iterator it = str.begin(); it != str.end(); ++it)
				if (*it >= 'a' && *it <= 'z')
					*it -= 'a' - 'A';
			std::cout << str;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}