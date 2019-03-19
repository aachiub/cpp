/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:35:41 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 19:27:34 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequest::RobotomyRequest( std::string const & target ) : Form ( "RobotomyRequest", 72, 45 ) {
    ((Form *)this)->setTarget( target );
	std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() \
										<< " and execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget() << std::endl;
   return ;
}

RobotomyRequest::RobotomyRequest( RobotomyRequest const & src ) : Form ( "Robotomy Request", 72, 45 ) {
    ((Form *)this)->setTarget( src.getTarget() );
	std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() \
										<< " and execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget() << std::endl;
    return ;
}

RobotomyRequest::~RobotomyRequest( void ) {
    return ;
}

RobotomyRequest & RobotomyRequest::operator = ( RobotomyRequest const & rhs ) {
    ((Form *)this)->setTarget( rhs.getTarget() );
    return *this;
}

std::string  RobotomyRequest::getTarget( void ) const {
    return ((Form *)this)->getTarget();
}

void  RobotomyRequest::setTarget( std::string const & target ) {
    ((Form *)this)->setTarget( target );
    return ;
}

void        RobotomyRequest::formExecute( void ) const {
	
	srand(time(NULL));
	int i = rand() % 2;
	std::cout << "Form " << this->getName() << ", " << this->getSignGrade()
										<< ", execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget();
	if ( i )
		std::cout << " has been successfully randomly robotomized" << std::endl;
 	else
		std::cout << ": random robotomization failure" << std::endl;
}
