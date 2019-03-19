/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:16:22 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 11:56:41 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define TXTNORMAL	"\033[0m"
#define TXTBLACK	"\033[1;30m"
#define TXTRED		"\033[1;31m"
#define TXTGREEN	"\033[1;32m"
#define TXTYELLOW	"\033[1;33m"
#define TXTBLUE		"\033[1;34m"
#define TXTMAGENTA	"\033[1;35m"

class Form;

class Bureaucrat {
public:

//    Bureaucrat( void ); does not make sense since name is constant ...
    Bureaucrat( std::string const & name, int const & grade );
    Bureaucrat( Bureaucrat const & src );
    ~Bureaucrat( void );

    Bureaucrat & operator = ( Bureaucrat const & rhs );

    std::string const &   getName( void );
    int &                 getGrade( void );

    void upGrade( void );
    void upGrade( int const & nGrade );
    void downGrade( void );
    void downGrade( int const & nGrade );

    void signForm( Form & form );

    class GradeTooHighException : public std::exception {
        public:
            GradeTooHighException( void );
            GradeTooHighException( GradeTooHighException const & e );
            ~GradeTooHighException( void ) throw();

            GradeTooHighException & operator = ( GradeTooHighException const & rhs );

            virtual const char * what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            GradeTooLowException( void );
            GradeTooLowException( GradeTooLowException const & e );
            ~GradeTooLowException( void ) throw();

            GradeTooLowException & operator = ( GradeTooLowException const & rhs );

            virtual const char * what() const throw();
    };

private:

    static const int    _highestGrade = 1;
    static const int    _lowestGrade = 150;

    std::string         _name;
    int                 _grade;

};

std::ostream & operator << ( std::ostream & os, Bureaucrat & rhs );

#endif
