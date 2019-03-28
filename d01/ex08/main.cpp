/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:53:27 by aachir            #+#    #+#             */
/*   Updated: 2019/03/27 15:28:39 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int main() {
    Human h;

    std::cout << std::endl;
    h.action( "meleeAttack", "Mountain Hill");

    std::cout << std::endl;
    h.action( "rangedAttack", "Black Stone");

    std::cout << std::endl;
    h.action( "intimidatingShout", "Cluster 3");

    std::cout << std::endl << "Simulating an error on an non existing action : " << OKBLUE << "Its_A_Joke" << NORMAL << std::endl;
    h.action( "Its_A_Joke", "Walou");

    std::cout << std::endl;
}