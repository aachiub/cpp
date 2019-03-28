/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:20:18 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:09:46 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#define ENDC        "\033[0m"
#define RED		    "\033[1;31m"

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {

public:
    Weapon( std::string const & type );
    ~Weapon( void );

    std::string const & getType( void );
    void setType( std::string const & type );
    
private:
    std::string     _type;

};

#endif
