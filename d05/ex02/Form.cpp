/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 07:28:19 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 19:12:24 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form( std::string const & name, const int & signGrade, const int execGrade ) : _name( name ), _signed( false ), _executed( false ) {

    if ( _isValidGrade ( signGrade ) && _isValidGrade ( execGrade ) ) {
        this->_signGrade  = signGrade;
        this->_executeGrade  = execGrade;
    }
    return ;
}

Form::Form( Form const & src ) {
    *this = src;
    return ;
}

Form::~Form( void ) {
    std::cout << "Form " << this->getName() << ", target " << this->getTarget() << " is deleted." << std::endl;
    return ;
}

Form & Form::operator = ( Form const & rhs ) {
    
    this->_name     = rhs.getName();
    this->_signGrade= rhs.getSignGrade();
    this->_signed   = rhs.isSigned();
    this->_executed = rhs.isExecuted();
    this->_executeGrade = rhs.getExecuteGrade();
    
    return *this;
}

std::string const & Form::getName( void ) const {
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

int const &  Form::getSignGrade( void ) const {
    return this->_signGrade;
}

bool        Form::isSigned( void ) const {
    return this->_signed;
}

void        Form::_setSigned( bool const & sign ) {
    this->_signed = sign;
    return ;
}

bool        Form::isExecuted( void ) const {
    return this->_executed;
}

void        Form::_setExecuted( bool const & exec ) {
    this->_executed = exec;
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

std::string  Form::getTarget( void ) const {
    return this->_target;
}

void  Form::setTarget( std::string const & target ) {
    this->_target = target;
    return ;
}

void        Form::beSigned(Bureaucrat  & executor) {

    if ( executor.getGrade() != this->_highestGrade &&  executor.getGrade() > this->getSignGrade() ) // if grade is high enough to sign
        throw Form::GradeTooLowException();
    
    else if ( this->isSigned() ) // already signed, nothing to do
        std::cout << "Form " <<  this->getName() << ", target " << this->getTarget() << " already signed !"<< std::endl;

    else
    {
       this->_signed = true;
       std::cout << executor.getName() <<  " signs "  <<  this->getName() << ", target " << this->getTarget() << std::endl;
    }

    return ;
}


void        Form::formExecute( void ) const {
    return ;
}

//void        Form::execute(Bureaucrat const & executor) const {
void        Form::execute(Bureaucrat & executor) {

    if ( executor.getGrade() != this->_highestGrade && executor.getGrade() > this->getExecuteGrade() ) // if grade is high enough to sign
        throw Form::GradeTooLowException();

    else if ( this->isExecuted() ) // already executed, nothing to do
        std::cout << "Form " <<  this->getName() << ", target " << this->getTarget() << " already executded !"<< std::endl;

    else if ( !this->isSigned() ) // not signed yet
        std::cout << "Form " <<  this->getName()  << ", target " << this->getTarget() << " not signed yet !"<< std::endl;

    else
    {
       this->_executed = true;
       std::cout << executor.getName() <<  " executes "  <<  this->getName() << ", target " << this->getTarget() << std::endl;
       this->formExecute();
    }

    return ;
}


// << operator overload
std::ostream  & operator << (std::ostream & os, Form const & rhs) {
    os << "Form " << rhs.getName() << ", sign grade " << rhs.getSignGrade() << ", execution grade " \
                                    << rhs.getExecuteGrade() << ", target " << rhs.getTarget();
    if ( !rhs.isSigned() )
        os << " not yet signed";
    else if ( !rhs.isExecuted() )
        os << " signed , not executed yet";
    else
        os << " signed and executed";
    return os << std::endl;
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
