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
#include <bits/stdc++.h>
#include <list>
#include <vector>

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

int Expression::getResult(void) {
    return this->_result;
}

Expression & Expression::operator = ( Expression const & rhs ) {
	this->_expr = rhs._expr;
	return (*this);
}

void 	Expression::_freeMem( void ) {
	for (std::vector< Token * >::iterator it = _postfix.begin(); it != _postfix.end(); it++ )
		free( *it );
}

bool 	Expression::_tokenize( void ) {
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
				this->_tokens.push_back( new Token( token ) );	
			}
			else if ( isdigit( str[ 0 ] ) ) {
				int value;
				std::stringstream ss( str ); 
    			ss >> value; 
				token.setValue ( value );			
				std::cout << token << " ";
				this->_tokens.push_back( new Token( token ) );	
			}
			else
				 return false; 
		}
		else {
			for(std::string::iterator it = str.begin(); it != str.end(); it++ ) {
				if ( *it == PAROPEN || *it == PARCLOSE ) {
					if ( *it == PAROPEN )
						token.setOperator( PAROPEN );			
					else
						token.setOperator( PARCLOSE );			
					std::cout << token << " ";
					this->_tokens.push_back( new Token( token ) );	
					*it = ' ';
				}
				else if ( isdigit( *it ) && token.getType() != TOK_INT) {
					int value;
					std::stringstream ss( str ); 
					ss >> value; 
					token.setValue ( value );			
					std::cout << token << " ";
					this->_tokens.push_back( new Token( token ) );	
				}
			}
		} 					
		if ( token.getType() == TOK_ERR )
			return false;
	}
	std::cout << std::endl;

    return true;
}

bool	Expression::_checkprecedence( Token *oper, Token *top )
{
	t_tokType opertype = oper->getType();
	t_tokType toptype = top->getType();

	if ( toptype == TOK_PAROPEN )
		return ( false );
	
	if ( opertype == TOK_ADD || opertype == TOK_SUB ) {
		return ( toptype == TOK_MUL || toptype == TOK_DIV );
	}

	return false;
}

bool 	Expression::_makeitpostfix( void ) {
	std::vector< Token * > 	operlist;
	int			nbpar;
	t_tokType 	type, prevtype;

	nbpar = 0;
	std::cout << "Postfix: ";
	prevtype = TOK_ERR;
	for (std::vector< Token * >::iterator it = _tokens.begin(); it != _tokens.end(); it++ )
	{
		type = (*it)->getType();

		if ( type == TOK_INT ) {
			if ( type == prevtype) {
				std::cout << MSG_INVALIDEXPRESSION << std::endl;
				_freeMem();
				return ( false );
			}
			else {
				_postfix.push_back ( *it );
				std::cout << **it << " ";
			}
		}
	
		else if ( type == TOK_PAROPEN ) {
			++nbpar;
			operlist.push_back( *it );
		}

		else if ( type == TOK_PARCLOSE ) {
			if ( --nbpar < 0 ) {
				std::cout << MSG_MISSINGPARENTHESIS << std::endl;
				_freeMem();
				return ( false );
			}

			if ( operlist.size() && nbpar > 0 ) {
				Token *tok = operlist.back();
				_postfix.push_back( tok );
				std::cout << *tok << " ";
				operlist.pop_back();
			}
			free ( *it );

			// remove corresponding open par.
			for (std::vector< Token * >::iterator it1 = operlist.end(); ; it1-- ) {
				if ( (*it1)->getType() == TOK_PAROPEN ) {
					operlist.erase ( it1 );					
					free( *it1 );
				}
				if ( it1 == operlist.begin() )
					break;
			}
		}
	
		else { // its an Operator

			if ( type == prevtype) {
				std::cout << MSG_INVALIDEXPRESSION << std::endl;
				_freeMem();
				return ( false );
			}

			// check precedence rules with previous operators and push appropriate ones
			while ( operlist.size() && _checkprecedence( *it, operlist.back() )) {
				Token *tok = operlist.back();
				operlist.pop_back();
				_postfix.push_back( tok );
				std::cout << *tok << " ";
			}
			operlist.push_back( *it );
		}

		prevtype = type;
	}

	// push remaing operators
	while ( operlist.size() ) {
		Token *tok = operlist.back();
		operlist.pop_back();
		if ( tok->getType() != TOK_PAROPEN ) {
			_postfix.push_back( tok );
			std::cout << *tok << " ";
		}
		else
			free ( tok );
	}

	std::cout << std::endl;

	if ( nbpar ) {
		std::cout << MSG_MISSINGPARENTHESIS << std::endl;
		_freeMem();
		return ( false );
	}
	return ( true ) ;
}

bool 	Expression::analyse( void ) {

	if ( _tokenize() )
		return ( _makeitpostfix() );
	std::cout << std::endl << MSG_INVALIDEXPRESSION << std::endl; 
	return ( false );
}

int 	Expression::compute( void ) {
	std::string 				post_msg[] = { "Add", "Substract", "Multiply", "Divide", "Push", "", "" };
	std::vector < Token * > 	stk;
	Token						*token;
	t_tokType					type;
	int							tmpresult;

	if ( !_postfix.size() )  {
		std::cout << MSG_EMPTYEXPRESSION << std::endl;
		_freeMem();
		return ( false );
	}

	for (std::vector< Token * >::iterator it = _postfix.begin(); it != _postfix.end(); it++ )
	{
		token = *it;
		type = token->getType();

		std::cout << "I " << **it ;
		
		if ( type == TOK_INT ) {
			std::cout << " | Op " << post_msg[ type ];
			stk.push_back( *it );
		}
		else { // it's an operator
			std::cout << "  | Op " << post_msg[ type ];

			// get first operand
			if ( stk.size() && ( token = stk.back() ) )  {
				int operand1 = token->getValue();
				free ( token );
				stk.pop_back();

			// get second operand
				if ( stk.size() && ( token = stk.back() ) )  {
					int operand2 = token->getValue();
					free ( token );
					stk.pop_back();
	
					if ( type == TOK_ADD )
						tmpresult = operand2 + operand1;
					else if ( type == TOK_SUB )
						tmpresult = operand2 - operand1;
					else if ( type == TOK_MUL )
						tmpresult = operand2 * operand1;
					else if ( type == TOK_DIV ) {
						if ( ! operand1 ) {
							std::cout << MSG_DIVIDEBYZERO << std::endl;
//							_freeMem();
							return ( false );
						}
						tmpresult = operand2 / operand1;
					}
				
				}
				else { // unary
					if ( type == TOK_DIV || type == TOK_MUL) {
						std::cout << MSG_INVALIDUNARY << std::endl;
//						_freeMem();
						return ( false );
					}

					tmpresult = (  type == TOK_SUB ) ? - operand1 : operand1;
				}

				// push result
				token = new  Token( TOK_INT, tmpresult );
				stk.push_back( token );
			}
			else {
				std::cout << MSG_INVALIDEXPRESSION << std::endl;
//				_freeMem();
				return ( false );
			}

			free ( *it );
		}

		// display stack content
		std::cout << "\t| ST";
		for (int i = stk.size() - 1; i >= 0; i-- )
			std::cout << " " << stk[ i ]->getValue();
		std::cout << "]" << std::endl;
	}
	
	if ( stk.size() && ( token = stk.back() ) )  {
		this->_result = token->getValue();
		free ( token );
		return true;
	}

	return false;
}
