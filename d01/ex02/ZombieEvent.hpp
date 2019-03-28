/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:19:41 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 12:54:14 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    
#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

public:
    ZombieEvent( void );
    ZombieEvent( std::string const & type );
    ZombieEvent( ZombieEvent const & src );
    ~ZombieEvent( void );

    ZombieEvent & operator = ( ZombieEvent const & rhs );


    std::string & getType( void );
    void setType( std::string const & name );
    
    Zombie* newZombie( std::string name );

    void    RandomChump( void );

private:
    std::string     _type;
};

std::ostream & operator << ( std::ostream & os, ZombieEvent & rhs );

#endif
