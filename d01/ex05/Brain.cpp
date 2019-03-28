/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:10:32 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 10:31:04 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Brain.hpp"

Brain::Brain( void ) {
    std::ostringstream os;
    
    os << this;
    _mbrainAddress = os.str();
}

Brain::~Brain( void ) {
    return ;
}

std::string & Brain::identify( void ) {
    return _mbrainAddress;
}

