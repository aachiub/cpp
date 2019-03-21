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
	int		evaluate( void );
	int		getResult( void );

private:

	bool 	_tokenize( void );
	bool 	_makeitpostfix( void );
	void 	_freeMem( void );

    std::string    		_expr;
	std::vector<Token *> _postfix;
	std::vector<Token *> _tokens;
  
	int			_result;

};



#endif
