/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:17:24 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 11:51:57 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Form.hpp"
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( std::string const & name, int const & grade ) : _name( name ) {
  
    if ( grade < this->_highestGrade )
       throw Bureaucrat::GradeTooHighException();
    else if ( grade > this->_lowestGrade )
        throw Bureaucrat::GradeTooLowException();
    else {
        this->_grade = grade;
        std::cout << this->_name <<  ", bureaucrat grade "  <<  this->_grade << ", has been hired";
    }

    if ( this->_grade == this->_highestGrade )
        std::cout << TXTRED << "\t\t\"... WHO'S THE BIG BOSS HERE !\"" << TXTNORMAL << std::endl;
    else if ( this->_grade == this->_lowestGrade )
        std::cout << TXTGREEN << "\t\t\"... One day I will become a little Boss too !\"" << TXTNORMAL << std::endl;
    else 
        std::cout << TXTYELLOW << "\t\t\"... I want to be the Big Boss !\"" << TXTNORMAL << std::endl;

    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat( void ) {
    std::cout << TXTRED <<  "YOU'RE FIRED !" << TXTNORMAL << "\t Too bad, bureaucrat " << this->_name << ", is leaving ..." << std::endl;
    return ;
}

Bureaucrat & Bureaucrat::operator = ( Bureaucrat const & rhs ) {
    this->_name = rhs._name;
    this->_grade = rhs._grade;
    return *this;
}

std::string const & Bureaucrat::getName( void ) {
    return this->_name;
}

int & Bureaucrat::getGrade( void ) {
    return this->_grade;
}

void Bureaucrat::upGrade( void ) {
    this->upGrade(1);
}

void Bureaucrat::upGrade( int const & nGrade ) {
    
    if ( this->_grade - nGrade < this->_highestGrade )
        throw Bureaucrat::GradeTooHighException ();
    else {
        this->_grade -= nGrade;
        std::cout << this->_name <<  ", has been upgraded to position "  <<  _grade << "." << std::endl;
    }

     return ;
 }

void Bureaucrat::downGrade( void ) {
    this->downGrade(1);
}

void Bureaucrat::downGrade( int const & nGrade ) {
    
    if ( this->_grade + nGrade > this->_lowestGrade )
           throw Bureaucrat::GradeTooLowException ();
    else { 
        this->_grade += nGrade;
        std::cout << this->_name <<  ", has been downgraded to position "  <<  this->_grade << "." << std::endl;
    }

    return ;
}

void Bureaucrat::signForm( Form & form ) {

    try {
       form.beSigned( *this );
    }

    catch (Form::GradeTooLowException (e) ) {
        std::cout << this->_name <<  " cannot sign "  <<  form.getName() << " because " << e.what() << std::endl;
    }

}


// << operator overload

std::ostream & operator << ( std::ostream  & os, Bureaucrat  & rhs  ) {
    return os << "I am " << rhs.getName() <<  ", my grade is "  <<  rhs.getGrade() << "." << std::endl;
} 


// Bureaucrat exception derived Classes

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {
    return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException  const & e ) {
    *this = e;
    return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {
    return ;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator = ( GradeTooHighException const & rhs ) {
    std::string unused = rhs.what();
    return *this;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ( "\033[1;31mCannot upgrade Bureaucrat too high !\033[0m");
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {
    return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const & e ) {
    *this = e;
    return ;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {
    return ;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator = ( GradeTooLowException const & rhs ) {
    std::string unused = rhs.what();
    return *this;
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("\033[1;31mCannot downgrade Bureaucrat too low !\033[0m");
}
