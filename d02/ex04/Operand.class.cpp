/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:57:22 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 18:58:08 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.class.hpp"
#include "Expression.class.hpp"

ExprMember::ExprMember( Fixed const & val, t_memberType const & type) : _val(val),  _type(type) {
	return ;
}

ExprMember::ExprMember( void ) {
	return ;
}

ExprMember::~ExprMember( void ) {
	return ;
}

Fixed ExprMember::getVal( void ) const {
	return this->_val;
}

void ExprMember::setVal( Fixed const & val ) {
	this->_val = val;
}


t_memberType ExprMember::getType( void ) const {
	return this->_type;
}

bool ExprMember::setType( t_memberType const & type ) {
	if (_type < T_PLUS || _type > T_OPERAND)
		return false;
	this->_type = type;
	return true;
}

void ExprMember::setType( char const & c ) {
	if ( c == O_PLUS )
		this->_type = T_PLUS;
	else if ( c == O_MINUS )
		this->_type = T_MINUS;
	else if ( c == O_MUL )
		this->_type = T_MUL;
	else if ( c == O_DIV )
		this->_type = T_DIV;
	else 
		this->_type = T_OPERAND;
	return ;
}
