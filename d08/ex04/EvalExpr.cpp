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

Expression & Expression::operator = ( Expression const & rhs ) {
	this->_expr = rhs._expr;
	return (*this);
}

void 	Expression::_freeMem( void ) {
	for (std::vector< Token * >::iterator it = _postfix.begin(); it != _postfix.end(); it++ ) {
		free( *it );
	}
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

bool 	Expression::_makeitpostfix( void ) {
	std::vector< Token * > 	operlist;
	int		nbpar;
	size_t 	size;
	Token	token;

	nbpar = 0;

	std::cout << "Postfix: ";
	for (std::vector< Token * >::iterator it = _tokens.begin(); it != _tokens.end(); it++ )
	{
		token = **it;

		if ( token.getType() == TOK_INT ) {
			_postfix.push_back ( *it );
			std::cout << **it << " ";
		}
	
		else if ( token.getType() == TOK_PAROPEN ) {
			++nbpar;
			free ( *it );
		}
	
		else if ( token.getType() == TOK_PARCLOSE ) {
			if ( --nbpar < 0 ) {
				_freeMem();
				return ( false );
			}

			if ( ( size = operlist.size() ) && nbpar > 0 ) {
				--size;
				_postfix.push_back( operlist[ size ] );
				std::cout << *operlist[ size ] << " ";
				operlist.resize ( size );
			}
			if ( nbpar == 0 && size ) {
				--size;
				_postfix.push_back( operlist[ size ] );
				std::cout << *operlist[ size ] << " ";
				operlist.resize ( size );
			}

			free ( *it );
		}
	
		else { // its an Operator
			if ( ( size = operlist.size() ) && nbpar == 0 ) {
				--size;
				_postfix.push_back( operlist[ size ] );
				std::cout << *operlist[ size ] << " ";
				operlist.resize ( size );
			}

			operlist.push_back( *it );
		}
	}

	if ( ( size = operlist.size() ) && nbpar == 0 ) {
			--size;
			_postfix.push_back( operlist[ size ] );
			std::cout << *operlist[ size ] << " ";
			operlist.resize ( size );
	}

	std::cout << std::endl;

	if ( nbpar ) {
		_freeMem();
		return ( false );
	}
	return ( true ) ;
}

bool 	Expression::analyse( void ) {

	if ( _tokenize() )
		return ( _makeitpostfix() );
	return ( false );
}

int 	Expression::evaluate( void ) {
	std::string 			post_msg[] = { "Add", "Substract", "Multiply", "Divide", "Push", "", "" };
	std::vector < Token * > 	lst;
	Token					token;
	t_tokType				type;
	size_t 					size;

	for (std::vector< Token * >::iterator it = _postfix.begin(); it != _postfix.end(); it++ )
	{
		token = **it;
		type =token.getType();

		std::cout << "[ " << **it ;
		
		if ( type == TOK_INT ) {
			std::cout << " | Op ";
			lst.push_back( *it );
		}
		else { // operator
			Token *tok, *tok1, *tok2;

			if ( ( size = lst.size() ))  {
				--size;
				tok1 = lst[ size ];
				lst.resize ( size );

				if ( ( size = lst.size() ))  {
					--size;
					tok2 = lst[ size ];
					lst.resize ( size );

					std::cout << "  | Op ";

					tok = new  Token( *tok1 );
					tok->setValue( this->_result );
					lst.insert( lst.begin(), tok );
					free ( tok2 );

				}
				else { // unary

				}
				free ( tok1 );
				free ( *it );
			}

		}

		// display stack content
		std::cout << post_msg[ type ] << "\t| ST ";
		for (int i = lst.size(); i > 0; i-- ) {
			std::cout << lst[ i ]->getValue() << " ";
		}
		std::cout << post_msg[ type ] << "]" << std::endl;

	}
	
//	_freeMem();

	std::cout << "Result : " << this->_result << std::endl;

	return true;
}
