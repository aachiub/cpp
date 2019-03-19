/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 07:28:19 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 12:12:21 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form( std::string const & name, int const & signGrade ) : _name( name ), _signed( false ) {

    if ( _isValidGrade ( signGrade ) ) {
        this->_signGrade  = signGrade;
        std::cout << "New Form " << this->getName() << " is created with sign grade " << this->getSignGrade() << std::endl;
    }
     this->_executeGrade = 1;
    return ;
}

Form::Form( Form const & src ) {
    *this = src;
    return ;
}

Form::~Form( void ) {
    std::cout << "Form " << this->_name << " is deleted." << std::endl;
    return ;
}

Form & Form::operator = ( Form const & rhs ) {
    
    this->_name     = rhs.getName();
    this->_signGrade= rhs.getSignGrade();
    this->_signed   = rhs.isSigned();
    
    return *this;
}

std::string const &  Form::getName( void ) const {
    return this->_name;
}

bool        Form::_isValidGrade( int const & grade ) const {

    if ( grade < this->_highestGrade )
        throw Form::GradeTooHighException();
    else if ( grade > this->_lowestGrade )
        throw Form::GradeTooLowException();
    else
        return true;
    return false;
} 

void         Form::setSignGrade( int const & grade ) {
    
    if ( _isValidGrade( grade ) )
        this->_signGrade = grade;
    return ;
}

int const & Form::getSignGrade( void ) const {
    return this->_signGrade;
}

bool        Form::isSigned( void ) const {
    return this->_signed;
}

void        Form::_setSigned( bool const & sign ) {
    this->_signed = sign;
    return ;
}

int  const & Form::getExecuteGrade( void ) const {
    return this->_executeGrade;
}

void 		Form::setExecuteGrade( int const & grade ) {
    if ( _isValidGrade( grade ) )
        this->_executeGrade = grade;
    return ;
}

void        Form::beSigned(Bureaucrat  & executor) {

    if ( executor.getGrade() != this->_highestGrade &&  executor.getGrade() > this->getSignGrade() ) // if grade is high enough to sign
        throw Form::GradeTooLowException();
    
    else if ( this->isSigned() ) // already signed, nothing to do
        std::cout << "Form " <<  this->getName() << " already signed !"<< std::endl;

    else
    {
       this->_signed = true;
       this->_signGrade = executor.getGrade();
       std::cout << executor.getName() <<  " signs "  <<  this->getName() << std::endl;
    }

    return ;
}


// << operator overload
std::ostream  & operator << (std::ostream & os, Form const & rhs) {
    os << "Form " << rhs.getName() << ", sign grade " << rhs.getSignGrade();
    if ( !rhs.isSigned() )
        os << " not yet";
    return os << " signed"<< std::endl;
}


// exceptions handling classes functions

// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException( void ) {
    return ;
}

Form::GradeTooHighException::GradeTooHighException( GradeTooHighException  const & e ) {
    *this = e;
    return ;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {
    return ;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator = ( GradeTooHighException const & rhs ) {
    std::string unused = rhs.what();
    return *this;
}

const char * Form::GradeTooHighException::what() const throw() {
    return ( "\033[1;31mgrade too high !\033[0m");
}


// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException( void ) {
    return ;
}

Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const & e ) {
    *this = e;
    return ;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {
    return ;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator = ( GradeTooLowException const & rhs ) {
    std::string unused = rhs.what();
    return *this;
}

const char * Form::GradeTooLowException::what() const throw() {
    return ("\033[1;31mgrade is too low !\033[0m");
}
