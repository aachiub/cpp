/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:11:56 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 15:27:08 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>

#define     NBALPHANUM  8

struct Data {
    std::string s1;
    int         n;
    std::string s2;
};

struct DataOnHeap {
    char    s1[NBALPHANUM];
    int     n;
    char    s2[NBALPHANUM];
};

class Serialization {

public:
    Serialization( void );
    Serialization( Serialization const & src );
    ~Serialization( void );
    Serialization &  operator = ( Serialization const & rhs );

    Data * deserialize( void * raw );
    void * serialize( void );

private:
};

#endif

