/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:54:37 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:25:28 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_HPP
#define _HUMAN_HPP

#include <iostream>

#define NORMAL	    "\033[0m"
#define RED		    "\033[1;31m"
#define OKBLUE      "\033[94m"

#define NFUNC    3

class Human {

    private:
        void meleeAttack(std::string const & target);
        void rangedAttack(std::string const & target);
        void intimidatingShout(std::string const & target);

    public:
        void action(std::string const & action_name, std::string const & target);

};

#endif