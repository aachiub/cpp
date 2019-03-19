/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:47:42 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 22:53:55 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token( void ) {
	this->_type = TOK_ERR;
    return ;
}

Token::Token( t_tokType const & type, char const & oper ) {
	this->_oper = oper;
	this->_type = type;
    return ;
}

Token::Token( t_tokType const & type, int const & value ) {
	this->_value = value;
	this->_type = type;
    return ;
}

Token::Token( Token const & src ) {
    *this = src;
    return ;
}

Token::~Token( void ) {
    return ;
}

Token & Token::operator = ( Token const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

char & Token::getOperator( void ) {
	return this->_oper;
}

int & Token::getValue( void ) {
	return this->_value;
}

t_tokType & Token::getType( void ) {
	return this->_type;
}

void Token::setOperator( const char& oper ) {
	this->_oper = oper; 
	if ( oper == ADD )
		this->_type = TOK_ADD;
	else if ( oper == SUB )
		this->_type = TOK_SUB;
	else if ( oper == MUL )
		this->_type = TOK_MUL;
	else if ( oper == DIV )
		this->_type = TOK_DIV;
	else if ( oper == PAROPEN )
		this->_type = TOK_PAROPEN;
	else if ( oper == PARCLOSE )
		this->_type = TOK_PARCLOSE;
	else
		this->_type = TOK_ERR;
}

void Token::setValue( int  & value ) {
	this->_value = value; 
	this->_type = TOK_INT; 
}
void Token::setType( t_tokType const & type) {
	this->_type = type; 
}

std::ostream & operator << ( std::ostream  & os, Token & rhs  ) {
	t_tokType t = rhs.getType();;
	if ( t == TOK_INT )
		std::cout << "Num(" << rhs.getValue() << ")";
	else if ( t == TOK_PAROPEN )
		std::cout << "ParOpen";
	else if ( t == TOK_PARCLOSE )
		std::cout << "ParClose";
	else if ( t != TOK_ERR )
		std::cout << "OP(" << rhs.getOperator() << ")";
	else
		os << "(?)";
    return os;
}

