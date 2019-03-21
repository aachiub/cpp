/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:41:46 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 21:52:40 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_HPP
# define TOKEN_HPP

#include "ostream"
#include <iostream>

#define ADD			'+'
#define SUB			'-'
#define MUL			'*'
#define DIV			'/'
#define PAROPEN		'('
#define PARCLOSE	')'
#define ERR			'?'

typedef enum e_token {
	TOK_ADD = 0,
	TOK_SUB,
	TOK_MUL,
	TOK_DIV,
	TOK_INT,
	TOK_PAROPEN,
	TOK_PARCLOSE,
	TOK_ERR,
}			t_tokType;


class Token {

public:
    Token( void );
	Token( t_tokType const & type, char const & oper );
	Token( t_tokType const & type, int const & value );
    Token( Token const & src );
    ~Token( void );

    Token & operator = ( Token const & rhs );

	char & 		getOperator( void );
	int  & 		getValue( void );
	t_tokType & getType( void );

	void 		setOperator( const char& oper );
	void 		setValue( int  & value );
	void		setType( t_tokType const & type);

private:
	char		_oper;
	t_tokType	_type;
	int			_value;

};

std::ostream & operator << ( std::ostream & os, Token & rhs );

#endif
