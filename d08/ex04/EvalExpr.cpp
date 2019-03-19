/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:37:08 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 23:20:04 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "EvalExpr.hpp"
#include "Token.hpp"
#include <sstream>
#include <stack>
#include <vector>
//#include <list>

Expression::Expression(void) {
	this->_result = 0;
    return ;
}

Expression::Expression( std::string const & expr ): _expr( expr ) {
	this->_result = 0;
    return ;
}

Expression::Expression( Expression const & src ) {
	*this = src;
    return ;
}

Expression::~Expression(void) {
    return ;
}

Expression & Expression::operator = ( Expression const & rhs ) {
	this->_expr = rhs._expr;
	return (*this);
}

bool Expression::analyse( std::string const & expr ) {
	this->_expr = expr;
	return ( this->analyse() );
}


bool Expression::analyse( void ) {

	std::istringstream iss( this->_expr );
	std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	std::string str;
	Token token;

	std::cout << "Tokens: ";
	for (std::vector< std::string >::iterator it = tokens.begin(); it != tokens.end(); it++ ) {
		token.setType( TOK_ERR );
	    str = *it;
		if ( str.size() == 1 ) {
			if ( str[0] == ADD || str[0] == SUB || str[0] == MUL || str[0] == DIV || str[0] == PAROPEN || str[0] == PARCLOSE ) {
				token.setOperator( str[0] );			
				std::cout << token << " ";
			}
			else if ( isdigit( str[ 0 ] ) ) {
				int value;
				std::stringstream ss( str ); 
    			ss >> value; 
				token.setValue ( value );			
				std::cout << token << " ";
			}
			else
				 return false; 
		}
		else {
			for(std::string::iterator it = str.begin(); it != str.end(); it++ ) {
				if ( *it == PAROPEN || *it == PARCLOSE ) {
					if ( *it == PAROPEN )	token.setOperator( PAROPEN );			
					else 					token.setOperator( PARCLOSE );			
					std::cout << token << " ";
					*it = ' ';
				}
				else if ( isdigit( *it ) && token.getType() != TOK_INT) {
					int value;
					std::stringstream ss( str ); 
					ss >> value; 
					token.setValue ( value );			
					std::cout << token << " ";
				}
			}
		} 					
		if (  token.getType() != TOK_ERR )
		; //	this->_tokList.push( token );	
		else
			return false;
	}
	std::cout << std::endl;

    return true;
}

int Expression::evaluate( void ) {

	this->_result = 0;
/*
	// display Tokens
	std::cout << "Tokens: ";
	for(int i = 0; i <  this->_tokList.size(); i++ )
		std::cout << token << " ";
	std::cout << std::endl;

*/	
	return this->_result;

}
