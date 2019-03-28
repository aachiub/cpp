/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 08:10:28 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:29:54 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

void Human::meleeAttack(std::string const & target){ 
    std::cout << "Launching \"meleeAttack\" on target : " << OKBLUE << target << NORMAL << std::endl;
}

void Human::rangedAttack(std::string const & target){ 
    std::cout << "Launching \"rangedAttack\" on target : " << OKBLUE << target << NORMAL << std::endl;
}

void Human::intimidatingShout(std::string const & target){ 
    std::cout << "Launching \"intimidatingShout\" on target : " << OKBLUE << target << NORMAL << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {

    // initializing maber function names array
    std::string fName[] = {  "meleeAttack", "rangedAttack", "intimidatingShout" };

    // initializing maber function pointers array
    void (Human::*fPtr[])(std::string const & ) = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };

	for (int i = 0; i < NFUNC; i++ )
        if ( fName[ i ] == action_name ) {
            ( this->*fPtr[ i ] )( target );
            return ;
        }
    std::cout << RED << "*** Error : " << NORMAL << "Human::" << action_name << "(std::string const &) does not exist." << std::endl;
}
