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

#define	MSG_DIVIDEBYZERO "\n\033[1;31mDivide by zero error.\033[0m\n"
#define	MSG_INVALIDUNARY "\n\033[1;31mInvalid unary operation.\033[0m\n"
#define	MSG_INVALIDEXPRESSION "\n\033[1;31mInvalid expression.\033[0m\n"
//#define	MSG_INVALIDEXPRESSION "\n\033[1;31mInvalid expression, only parentheses, integers, and the '+' '−' '/' '∗' operators are allowed.\033[0m\n"
#define	MSG_MISSINGPARENTHESIS "\n\033[1;31mMissing parenthesis.\033[0m\n"
#define	MSG_EMPTYEXPRESSION "\n\033[1;31mVoid expression. Missing operands.\033[0m\n"



class Expression {

public:
    Expression( void );
    Expression( std::string const & expr );
    Expression( Expression const & src );
    ~Expression( void );

    Expression & operator = ( Expression const & rhs );

    void 	setExpr( std::string const & expr );

	bool 	analyse( void );
	bool 	analyse( std::string const & expr );
	int		compute( void );
	int		getResult( void );

private:

	bool 	_tokenize( void );
	bool 	_makeitpostfix( void );
	void 	_freeMem( void );
	bool 	_checkprecedence( Token *oper, Token *top );

    std::string    		_expr;
	std::vector<Token *> _postfix;
	std::vector<Token *> _tokens;
  
	int			_result;

};



#endif
