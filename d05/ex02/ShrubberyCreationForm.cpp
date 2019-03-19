/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:35:54 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 19:13:20 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreation::ShrubberyCreation( std::string const & target ) : Form ( "Shrubbery Creation", 145, 137 ) {
    ((Form *)this)->setTarget( target );
	std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() \
										<< " and execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget() << std::endl;
    return ;
}

ShrubberyCreation::ShrubberyCreation( ShrubberyCreation const & src ) : Form ( "Shrubbery Creation", 145, 137 ) {
    ((Form *)this)->setTarget( src.getTarget() );
	std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() \
										<< " and execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget() << std::endl;
    return ;
}

ShrubberyCreation::~ShrubberyCreation( void ) {
    return ;
}

ShrubberyCreation & ShrubberyCreation::operator = ( ShrubberyCreation const & rhs ) {
    ((Form *)this)->setTarget( rhs.getTarget() );
    return *this;
}

std::string  ShrubberyCreation::getTarget( void ) const {
    return ((Form *)this)->getTarget();
}

void  ShrubberyCreation::setTarget( std::string const & target ) {
    ((Form *)this)->setTarget( target );
    return ;
}

void        ShrubberyCreation::formExecute( void ) const {

	std::string fname = this->getTarget() + "_shrubbery";

	std::ofstream f (fname, std::ios::out | std::ios::trunc );  // on ouvre le fichier en lecture
	if( f ) {       
		f	<< "         /\\         " << std::endl \
			<< "        /  \\        " << std::endl \
			<< "       /    \\       " << std::endl \
			<< "      /      \\      " << std::endl \
			<< "     /        \\     " << std::endl \
			<< "    /          \\    " << std::endl \
			<< "        | |          " << std::endl \
			<< "        | |          " << std::endl \
			<< "                     " << std::endl;
		f.close();
	}	
}

