/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:12:16 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:12:54 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main() {
    Human bob;

    std::cout   << OKBLUE << std::endl << "Brain address using Human::identify() : " << NORMAL \
                << bob.identify() << std::endl;
    
    std::cout   << OKBLUE << std::endl << "Brain address using Human::getBrain().identify() : " << NORMAL \
                << bob.getBrain().identify() << std::endl;

    return ( 0 );
}