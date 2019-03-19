/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 07:28:03 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 12:12:21 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
//#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:

//	Form( void ); // useless
	Form( std::string const & name, int const& signGrade );
	Form( Form const & src );
	~Form( void );

	Form & operator = ( Form const & rhs );

	std::string	const & getName( void ) const;
	int const &         getSignGrade( void ) const;
	int const &	        getExecuteGrade( void ) const;

	void 		setSignGrade( int const & grade );
	void 		setExecuteGrade( int const & grade );

	bool 		isSigned( void ) const;
    void        beSigned( Bureaucrat  & bur);

	bool 		isExecuted( void ) const;
 
    // Exceptions handling classes
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

	std::string _name;
	int         _signGrade;
    int         _executeGrade;    
	bool		_signed;
	bool		_executed;

    bool        _isValidGrade( int const & grade ) const;
	void 		_setSigned( bool const & sign );
	void 		_setExecuted( bool const & exec );
};

std::ostream & operator << (std::ostream & os, Form const & rhs);

#endif
