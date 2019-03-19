/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 07:28:03 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 18:02:15 by aachir           ###   ########.fr       */
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
	Form( std::string const & name, const int & signGrade, const int execGrade );
	Form( Form const & src );
	~Form( void );

	Form & operator = ( Form const & rhs );

	std::string	const & getName( void ) const;

	int const & getSignGrade( void ) const;
	int const &	getExecuteGrade( void ) const;

	void 		setSignGrade( int const & grade );
	void 		setExecuteGrade( int const & grade );

	bool 		isSigned( void ) const;
    void        beSigned( Bureaucrat  & bur);

	bool 		isExecuted( void ) const;

	std::string getTarget( void ) const;
	void		setTarget( std::string const & target );

//    void        execute(Bureaucrat const & executor) const;
    void            execute( Bureaucrat & executor);
    virtual void    formExecute( void ) const;

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
	bool		_signed;
    int         _executeGrade;    
	bool		_executed;

	std::string	_target;

    bool        _isValidGrade( int const & grade ) const;
	void 		_setSigned( bool const & sign );
	void 		_setExecuted( bool const & exec );
};

std::ostream & operator << (std::ostream & os, Form const & rhs);

#endif
