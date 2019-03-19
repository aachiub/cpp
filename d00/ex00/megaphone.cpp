/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:49:15 by aachir            #+#    #+#             */
/*   Updated: 2019/01/07 10:02:53 by aachir           ###   ########.fr       */
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