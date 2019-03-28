/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 08:15:05 by aachir            #+#    #+#             */
/*   Updated: 2019/03/28 10:40:47 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <list>
#include <vector>
#include <iostream>
#include "EvalExpr.hpp"
#include "Token.hpp"
#include "Fixed.class.hpp"

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

bool 	Expression::_expressionMember( t_tokType type ) {
	return ( type == TOK_INT || type ==	TOK_ADD || type == TOK_SUB || type == TOK_MUL || \
								type == TOK_DIV || type == TOK_INT );

}

void 	Expression::_freeTokens( std::vector<Token *> & vect ) {
	std::vector< Token * >::iterator it;
return ;
	for ( it = vect.begin(); it != vect.end(); it++ )
		free( *it );
}

void 	Expression::_freeMem( void ) {
//	_freeTokens( _tokens );
//	_freeTokens( _postfix );
}

bool 	Expression::_tokenize( void ) {
	std::istringstream iss( this->_expr );
	std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	std::string str;
	Token token;

	for (std::vector< std::string >::iterator it = tokens.begin(); it != tokens.end(); it++ ) {
		token.setType( TOK_ERR );
	    str = *it;

		if ( str.size() == 1 ) {
			if ( str[0] == ADD || str[0] == SUB || str[0] == MUL || str[0] == DIV || str[0] == PAROPEN || str[0] == PARCLOSE ) {
				token.setOperator( str[0] );			
				this->_tokens.push_back( new Token( token ) );	
			}
			else if ( isdigit( str[ 0 ] ) ) {
				int value;
				std::stringstream ss( str ); 
    			ss >> value; 
				token.setValue ( value );			
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
					this->_tokens.push_back( new Token( token ) );	
					*it = ' ';
				}
				else if ( isdigit( *it ) && token.getType() != TOK_INT) {
					int value;
					std::stringstream ss( str ); 
					ss >> value; 
					token.setValue ( value );			
					this->_tokens.push_back( new Token( token ) );	
				}
			}
		} 					
		if ( token.getType() == TOK_ERR )
			return false;
	}

    return true;
}

bool	Expression::_checkPreceedence( Token *oper, Token *top )
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

bool 	Expression::_makeitPostfix( void ) {
	std::vector< Token * > 	operlist;
	int			nbpar;
	t_tokType 	type, prevtype;

	nbpar = 0;
	prevtype = TOK_ERR;
	for (std::vector< Token * >::iterator it = _tokens.begin(); it != _tokens.end(); it++ )
	{
		type = (*it)->getType();

		if ( type == TOK_INT ) {
			if ( type == prevtype) {
				std::cout << MSG_INVALIDEXPRESSION << std::endl;
				_freeTokens( operlist );
				return ( false );
			}
			else {
				_postfix.push_back ( *it );
			}
		}
	
		else if ( type == TOK_PAROPEN ) {
			++nbpar;
			operlist.push_back( *it );
		}

		else if ( type == TOK_PARCLOSE ) {
			if ( --nbpar < 0 ) {
				std::cout << MSG_MISSINGPARENTHESIS << std::endl;
				_freeTokens( operlist );
				return ( false );
			}

			// push last operator
			if ( operlist.size() ) {
				Token *tok = operlist.back();
//				if ( tok->getType() != TOK_PAROPEN ) {
				if ( _expressionMember( tok->getType() ) ) {
					_postfix.push_back( tok );
					operlist.pop_back();
				}
			}

			// remove corresponding open par.
			for (std::vector< Token * >::iterator it1 = operlist.end() - 1; ; it1-- ) {
				if ( (*it1)->getType() == TOK_PAROPEN ) {
//					operlist.erase ( it1 , it1);					
//					free( *it1 );
					(*it1)->setType( TOK_ERR );
				}
				if ( it1 == operlist.begin() )
					break;
			}

			free ( *it );
		}
	
		else { // its an Operator

			if ( type == prevtype) {
				std::cout << MSG_INVALIDEXPRESSION << std::endl;
				_freeTokens( operlist );
				return ( false );
			}

			// check precedence rules with previous operators and push appropriate ones
			while ( operlist.size() && _checkPreceedence( *it, operlist.back() )) {
				Token *tok = operlist.back();
//				if ( tok->getType() != TOK_PAROPEN ) {
				if ( _expressionMember( tok->getType() ) ) {
					operlist.pop_back();
					_postfix.push_back( tok );
				}
			}
			operlist.push_back( *it );
		}

		prevtype = type;
	}

	if ( nbpar ) {
		std::cout << MSG_MISSINGPARENTHESIS << std::endl;
		_freeTokens( operlist );
		return ( false );
	}

	// push remaing operators
	while ( operlist.size() ) {
		Token *tok = operlist.back();
		operlist.pop_back();
//		if ( tok->getType() != TOK_PAROPEN ) {
		if ( _expressionMember( tok->getType() ) ) {
			_postfix.push_back( tok );
		}
	}
	_freeTokens( operlist );

	return ( true ) ;
}

bool 	Expression::analyse( void ) {

	if ( _tokenize() && _makeitPostfix() )
		return ( true );
	
	std::cout << std::endl << MSG_INVALIDEXPRESSION << std::endl; 
	_freeMem();

	return ( false );
}

// using a stack
/*
int  Expression::evalExpression( void ) {
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
		
//		if (t2 == T_OPERAND)
//			res = binary(t, o1, o2);		
//		else
//			res = unary(t, o1);

        _stack.pop(); 
    } 

	return _result;
}
*/

int 	Expression::compute( void ) {
	std::string 				post_msg[] = { "Add", "Substract", "Multiply", "Divide", "Push", "", "" };
	std::vector < Token * > 	stk;
	Token						*token;
	t_tokType					type;
	int							tmpresult;

	if ( !_postfix.size() )  {
		std::cout << MSG_EMPTYEXPRESSION << std::endl;
		_freeTokens( stk );
		_freeMem();
		return ( false );
	}

	for (std::vector< Token * >::iterator it = _postfix.begin(); it != _postfix.end(); it++ )
	{
		token = *it;
		type = token->getType();

		if ( type == TOK_INT ) {
			stk.push_back( *it );
		}
		else { // it's an operator

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
						if ( operand1 == 0 ) {
							std::cout << MSG_DIVIDEBYZERO << std::endl;
							_freeTokens( stk );
							_freeMem();
							return ( false );
						}
						tmpresult = operand2 / operand1;
					}
				
				}
				else { // unary
					if ( type == TOK_DIV || type == TOK_MUL) {
						std::cout << MSG_INVALIDUNARY << std::endl;
						_freeTokens( stk );
						_freeMem();
						return ( false );
					}

					tmpresult = (  type == TOK_SUB ) ? - operand1 : operand1;
				}

				// push result
				token = new  Token( TOK_INT, tmpresult );
				stk.push_back( token );
			}
			else {
				std::cout << MSG_EXPECTINGEXPRESSION << std::endl;
				_freeTokens( stk );
				_freeMem();
				return ( false );
			}

			free ( *it );
		}

	}
	
	if ( stk.size() && ( token = stk.back() ) )  {
		this->_result = token->getValue();
		free ( token );
		return true;
	}

	_freeTokens( stk );
	_freeMem();
	return false;
}
