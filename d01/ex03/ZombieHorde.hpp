/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:30:08 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 13:43:55 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


    
#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieHorde {

public:
    ZombieHorde( int N );
    ZombieHorde( ZombieHorde const & src );
    ~ZombieHorde( void );

    ZombieHorde & operator = ( ZombieHorde const & rhs );

    void announce( void );

    void    RandomChump( int nZombies );

private:
    Zombie  **_zombieHorde;
    int     _nZombies;
};

#endif
