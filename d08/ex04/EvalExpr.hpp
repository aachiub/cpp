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

private:
    std::string    		_expr;
	std::stack<Token> 	_tokList;
  
	int			_result;

};



#endif
