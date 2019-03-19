/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:44:24 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 18:59:47 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPRESSION_HPP
# define EXPRESSION_HPP

#include <iostream>
#include <stack>
#include "Fixed.class.hpp"
#include "Operand.class.hpp"

class Expression {

public:
	Expression( std::string & expr );
	~Expression();

	bool 	validExpression( void );
	Fixed 	evalExpression( void );

private:

	std::string				_expr;
	std::stack<ExprMember>	_stack;
	Fixed					_result;
};

#endif