/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:55:25 by aachir            #+#    #+#             */
/*   Updated: 2019/01/10 18:58:05 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#define	O_PLUS 	'+'
#define	O_MINUS '-'
#define	O_MUL 	'*'
#define	O_DIV 	'/'
#define	O_EQUAL '='

typedef enum e_memberType {
	T_PLUS,
	T_MINUS,
	T_MUL,
	T_DIV,
	T_EQU,
	T_OPERAND,
	T_NOTYPE
}			t_memberType;

class ExprMember {
	
public:
	ExprMember( Fixed const & val, t_memberType const & type );
	ExprMember( void );
	~ExprMember( void );

	t_memberType 	getType( void ) const;
	bool			setType( t_memberType const & type );
	void			setType( char const & c );
	Fixed 		 	getVal( void ) const;
	void			setVal( Fixed const & val );

private:
	t_memberType	_type;
	Fixed			_val;
};

#endif