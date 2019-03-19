/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:11:41 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 15:36:39 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

typedef enum e_classIndex {
    A_class = 0,
    B_class,
    C_class,
    NO_class
}           t_classIndex;

class Base {

public:
    virtual ~Base() {}

private:

};


class A: public Base {

public:
   A( void );
   A( A const & src );
   ~A( void );
   A & operator = ( A const & rhs );

private:

};

class B: public Base {

public:
   B( void );
   B( B const & src );
   ~B( void );
   B & operator = ( B const & rhs );

private:

};

class C: public Base {

public:
   C( void );
   C( C const & src );
   ~C( void );
   C & operator = ( C const & rhs );

private:

};

#endif