/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:16:54 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 19:15:58 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



void    Execute(Bureaucrat & executor, Form & form) {

    std::cout << std::endl<< "***** \"" << executor.getName() << "\" tries to sign and execute Form "
                         << form.getName() << ", target " << form.getTarget() << std::endl;
    try {
            executor.signForm(form);
            executor.executeForm(form);
    }
    catch (Form::GradeTooHighException e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

}


int main()
{

    std::cout << std::endl << "***** Bureaucrats hiring session" << std::endl;
    std::cout << std::endl;
    Bureaucrat somebody("Somebody", 135);     Bureaucrat littleBoss("LittleBoss", 40);     Bureaucrat bigBoss("BigBoss", 1);
   
    std::cout << std::endl << "***** Bureaucrat list" << std::endl;
    std::cout << somebody << littleBoss << bigBoss << std::endl;



    std::cout << std::endl << "***** PresidentialPardon Forms creation" << std::endl;
    PresidentialPardon f1("Joe Dalton");    PresidentialPardon f2("Calamity Jane");     PresidentialPardon f3("Jessie James");

    std::cout << std::endl << "***** PresidentialPardon Forms Execution" << std::endl;
    Execute(somebody, f1);      Execute(somebody, f2);      Execute(somebody, f3);
    Execute(littleBoss, f1);    Execute(littleBoss, f2);    Execute(littleBoss, f3);
    Execute(bigBoss, f1);       Execute(bigBoss, f2);       Execute(bigBoss, f3);

    std::cout << std::endl << "***** PresidentialPardon Form list" << std::endl;
    std::cout << f1 << f2 << f3 << std::endl;



    std::cout << std::endl << "***** ShrubberyCreation Forms creation" << std::endl;
    ShrubberyCreation f4("Home");    ShrubberyCreation f5("Park");     ShrubberyCreation f6("Garden");

    std::cout << std::endl << "***** ShrubberyCreation Forms Execution" << std::endl;
    Execute(somebody, f4);      Execute(somebody, f5);      Execute(somebody, f6);
    Execute(littleBoss, f4);    Execute(littleBoss, f5);    Execute(littleBoss, f6);
    Execute(bigBoss, f4);       Execute(bigBoss, f5);       Execute(bigBoss, f6);

    std::cout << std::endl << "***** ShrubberyCreation Form list" << std::endl;
    std::cout << f4 << f5 << f6 << std::endl;



    std::cout << std::endl << "***** RobotomyRequest Forms creation" << std::endl;
    RobotomyRequest f7("John");    RobotomyRequest f8("Paul");  RobotomyRequest f9("Georges");

    std::cout << std::endl << "***** RobotomyRequest Forms Execution" << std::endl;
    Execute(somebody, f7);      Execute(somebody, f8);      Execute(somebody,f9);
    Execute(littleBoss, f7);    Execute(littleBoss, f8);    Execute(littleBoss, f9);
    Execute(bigBoss, f7);       Execute(bigBoss, f8);       Execute(bigBoss, f9);

    std::cout << std::endl << "***** RobotomyRequest Form list" << std::endl;
    std::cout << f7 << f8 << f9 << std::endl;

    std::cout << std::endl << "*****  Forms and Bureaucrats deletion" << std::endl;
    return 0;
}