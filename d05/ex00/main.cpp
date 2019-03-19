/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:16:54 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 11:50:04 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl << "*** Hiring Bureaucrats" << std::endl;
    Bureaucrat Nobody("Nobody", 150);
    Bureaucrat LittleBoss("LittleBoss", 10);
    Bureaucrat BigBoss("BigBoss", 1);

    std::cout << "*** Bureaucrat list" << std::endl;
    std::cout << std::endl << Nobody << LittleBoss << BigBoss << std::endl;

    try {
            std::cout << "*** Hiring Bureaucrat \"Zero\" at position 0 " << std::endl;
            Bureaucrat Zero("Zero", 0);
    }
    catch (Bureaucrat::GradeTooHighException e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
            std::cout << "*** Hiring Bureaucrat \"SixteenHundred\" at position 160 " << std::endl;
            Bureaucrat SixteenHundred("SixteenHundred", 160);
    }
    catch (Bureaucrat::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
            std::cout << "*** Try downgrade by 1 position " << Nobody.getName() << std::endl;
            Nobody.downGrade();
    }
    catch (Bureaucrat::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << Nobody << std::endl << std::endl;

    try {
        std::cout << "*** Try upgrade by 1 position " << LittleBoss.getName() << std::endl;
        LittleBoss.upGrade();
    }
    catch (Bureaucrat::GradeTooHighException e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << LittleBoss << std::endl << std::endl;;


    try {
        std::cout << "*** Try upgrade by 1 position " << BigBoss.getName() << std::endl;
        BigBoss.upGrade();
    }
    catch (Bureaucrat::GradeTooHighException e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << BigBoss << std::endl;


    try {
        std::cout << "*** Try upgrade by 5 positions " << LittleBoss.getName() << std::endl;
        LittleBoss.upGrade(5);
    }
    catch (Bureaucrat::GradeTooHighException e) {
        std::cout << e.what() << std::endl << std::endl;;
    }
    std::cout << LittleBoss << std::endl;


    std::cout << "*** Bureaucrat list" << std::endl;
    std::cout << Nobody << LittleBoss << BigBoss << std::endl << std::endl;

    return 0;
}