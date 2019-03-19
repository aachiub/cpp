/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:16:54 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 10:33:49 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{

    std::cout << std::endl << "*** Bureaucrats hiring :" << std::endl;
    std::cout << std::endl;
    Bureaucrat nobody("Nobody", 150);
    Bureaucrat littleBoss("LittleBoss", 8);
    Bureaucrat bigBoss("BigBoss", 1);

    std::cout << std::endl;

    std::cout << std::endl << "*** Forms creation :" << std::endl;
    Form f1("1-A", 5);
    Form f10("10-B", 10);
    Form f150("150-C", 149);

    std::cout << std::endl << "*** Bureaucrat list :" << std::endl;
    std::cout << nobody << littleBoss << bigBoss << std::endl;

    std::cout << std::endl << "*** Form list :" << std::endl;
    std::cout << f1 << f10 << f150 << std::endl;


    try {
            std::cout << "Trying to create form with grade 0 " << std::endl;
            Form f("void", 0);
    }
    catch (Form::GradeTooHighException e) {
        std::cout << e.what() << std::endl;
    }


    try {
            std::cout << std::endl << "Trying to create form with grade 160 " << std::endl;
            Form f("void", 160);
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }


    try {
            std::cout << std::endl << "\"Little Boss\" asked \"Nobody\" to sign Form 150-C " << std::endl;
            nobody.signForm(f150);
    }
    catch (Form::GradeTooHighException e) {
        std::cout << e.what() << std::endl;
    }

   try {
            std::cout << std::endl << "\"Nobody\" is upgraded and gains 1 position" << std::endl;
            nobody.upGrade( 1);
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

    try {
            std::cout << std::endl << "\"Little Boss\" asked again \"Nobody\" to sign Form 150-C " << std::endl;
            nobody.signForm(f150);
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

    try {
            std::cout << std::endl << "\"Nobody\" does not remember if he signs Form 150-C, so he tried one more time ... " << std::endl;
            nobody.signForm(f150);
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

    try {
            std::cout << std::endl << "\"Big Boss\" asked \"Little Boss\" to sign Form 10-B " << std::endl;
            littleBoss.signForm(f10);
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

    try {
            std::cout << std::endl << "\"Big Boss\" tries to sign Form 1-A " << std::endl;
            bigBoss.signForm(f1);
    }
    catch (Form::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "*** Form list :" << std::endl;
    std::cout << f1 << f10 << f150 << std::endl;

    return 0;
}