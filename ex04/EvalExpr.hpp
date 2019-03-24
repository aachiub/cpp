/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:33:18 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 23:17:30 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_HPP
# define EVALEXPR_HPP

#include <stack>
#include <vector>
#include "Token.hpp"

#define	TXTNORMAL	"\033[0m"
#define	TXTBLUE		"\033[1;34m"
#define	TXTRED		"\033[1;31m"
#define	TXTGREEN	"\033[1;32m"

#define	MSG_DIVIDEBYZERO "\033[1;31m\nDivide by zero error.\033[0m"
#define	MSG_INVALIDUNARY "\033[1;31mInvalid unary operation.\033[0m"
#define	MSG_INVALIDEXPRESSION "\033[1;31mInvalid expression.\033[0m"
#define	MSG_EXPECTINGEXPRESSION "\033[1;31m\nExpecting expression.\033[0m"
//#define	MSG_INVALIDEXPRESSION "\033[1;31mInvalid expression, only parentheses, integers, and the '+' '−' '/' '∗' operators are allowed.\033[0m"
#define	MSG_MISSINGPARENTHESIS "\033[1;31mMissing parenthesis.\033[0m"
#define	MSG_EMPTYEXPRESSION "\033[1;31mNot an expression. Missing operands.\033[0m"



class Expression {

public:
    Expression( void );
    Expression( std::string const & expr );
    Expression( Expression const & src );
    ~Expression( void );

    Expression & operator = ( Expression const & rhs );

	bool 	analyse( void );
	bool 	analyse( std::string const & expr );
	int		compute( void );
	int		getResult( void );

private:

	bool 	_tokenize( void );
	bool 	_makeitPostfix( void );
	void 	_freeTokens( std::vector<Token *> & vect );
	void 	_freeMem( void );
	bool 	_checkPreceedence( Token *oper, Token *top );
	bool 	_expressionMember( t_tokType type );

    std::string    		_expr;
	std::vector<Token *> _postfix;
	std::vector<Token *> _tokens;
  
	int			_result;

};



#endif
