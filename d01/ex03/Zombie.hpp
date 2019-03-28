/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:19:00 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 13:19:01 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

#define NORMAL  	"\033[0m"
#define RED	    	"\033[1;31m"
#define WARNING     "\033[93m"
#define BOLD        "\033[1m"
#define OKGREEN     "\033[92m"
#define OKBLUE      "\033[94m"


class Zombie {

public:
    Zombie( void );
    Zombie( std::string const & name, std::string const & type );
    Zombie( Zombie const & src );
    ~Zombie( void );

    Zombie & operator = ( Zombie const & rhs );

    std::string & getName( void );
    void setName( std::string const & name );
    std::string & getType( void );
    void setType( std::string const & name );

    void announce( void );

private:

    std::string     _name;
    std::string     _type;
};

#endif
