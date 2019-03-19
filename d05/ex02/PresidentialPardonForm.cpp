/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:34:51 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 19:13:16 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardon::PresidentialPardon( std::string const & target ) : Form ( "Presidential Pardon", 25, 5 ) {
    ((Form *)this)->setTarget( target );
	std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() \
										<< " and execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget() << std::endl;
    return ;
}

PresidentialPardon::PresidentialPardon( PresidentialPardon const & src ) : Form ( "Presidential Pardon", 25, 5 ) {
    ((Form *)this)->setTarget( src.getTarget() );
	std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() \
										<< " and execution grade " << this->getExecuteGrade() \
										<< ", target " << this->getTarget() << std::endl;
    return ;
}

PresidentialPardon::~PresidentialPardon( void ) {
    return ;
}

PresidentialPardon & PresidentialPardon::operator = ( PresidentialPardon const & rhs ) {
    ((Form *)this)->setTarget( rhs.getTarget() );
    return *this;
}

std::string  PresidentialPardon::getTarget( void ) const {
    return ((Form *)this)->getTarget();
}

void  PresidentialPardon::setTarget( std::string const & target ) {
    ((Form *)this)->setTarget( target );
    return ;
}

void        PresidentialPardon::formExecute( void ) const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}
