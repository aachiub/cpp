/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:51:20 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 19:07:28 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "Fixed.class.hpp"
#include "Expression.class.hpp"

Expression::Expression( std::string & expr ) : _expr( expr ), _result(0) {
	return ;
}

Expression::~Expression( void ) {
	return ;
}

bool Expression::validExpression( void ) {

	return true;
}

Fixed  Expression::evalExpression( void ) {
	ExprMember o, o1, o2;
	t_memberType t, t1, t2;

   	while (!_stack.empty()) { 
		o = _stack.top();
		t = o.getType;
		if (t == T_OPERAND)
			return o.getVal();
		_stack.pop();

		o1 = _stack.top();
		t1 = o1.getType;
		_stack.pop();

		o2 = _stack.top();
		t2 = o2.getType;
/*		
		if (t2 == T_OPERAND)
			res = binary(t, o1, o2);		
		else
			res = unary(t, o1);
*/
        _stack.pop(); 
    } 

	return _result;
}

