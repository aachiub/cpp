/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:59:14 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:07:37 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    
#ifndef HUMAN_HPP
# define HUMAN_HPP

#define OKBLUE      "\033[94m"
#define NORMAL	    "\033[0m"

#include "Brain.hpp"

class Human {

public:
    Human( void );
    ~Human( void );

    std::string & identify( void );
    Brain & getBrain( void );

private:

    Brain   *_mBrain;
};

#endif
