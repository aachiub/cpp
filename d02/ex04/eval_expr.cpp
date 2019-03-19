/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:31:14 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 16:50:29 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"
#include "Expression.class.hpp"

int	main(int ac, char ** av) {
	if (ac != 1)
		return (1);
	
	std::string str = av[1];
	Expression e(str);
	return e.evaluate();
}