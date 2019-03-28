/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:10:25 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 10:31:01 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp"

Human::Human( void ) {
    _mBrain = new Brain();
    return ;
}

Human::~Human( void ) {
    delete _mBrain;
    return ;
}

std::string & Human::identify( void ) {
     return _mBrain->identify();
}

Brain & Human::getBrain( void ) {
     return *_mBrain;
}
