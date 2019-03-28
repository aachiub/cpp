/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:00:51 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 10:30:59 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

public:
    Brain( void );
    ~Brain( void );

    std::string & identify( void ) ;

private:

    std::string     _mbrainAddress;
};

#endif
