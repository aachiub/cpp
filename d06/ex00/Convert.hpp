/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:02:29 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 21:12:55 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#define TXTNORMAL	"\033[0m"
#define TXTBLACK	"\033[1;30m"
#define TXTRED		"\033[1;31m"
#define TXTGREEN	"\033[1;32m"
#define TXTYELLOW	"\033[1;33m"
#define TXTBLUE		"\033[1;34m"
#define TXTMAGENTA	"\033[1;35m"

class Convert {

public:
    Convert( void );
    Convert( Convert const & src );
    ~Convert( void );

    Convert & operator = ( Convert const & rhs );

	void  toTypes( std::string & strVal );

    // Impossible conversion and Non displayable char Exceptions handling classes
    class ImpossibleException : public std::exception
    {
    public:
        ImpossibleException( void );
        ImpossibleException( ImpossibleException const &src );
        virtual ~ImpossibleException( void ) throw();
     
        ImpossibleException & operator = ( const ImpossibleException &rhs );
     
        const char *what( void ) const throw();
    };

    class NonDisplayableException : public std::exception
    {
    public:
        NonDisplayableException( void );
        NonDisplayableException( NonDisplayableException const &src );
        virtual ~NonDisplayableException( void ) throw();
     
        NonDisplayableException & operator = ( const NonDisplayableException &rhs );
     
        const char *what( void ) const throw();
    };


private:

	void _toChar( double & dVal, bool issFail );
    void _toInt( double & dVal, bool issFail );
    void _toDouble( double & dVal, int precision, bool issFail );
    void _toFloat( double & dVal, int precision, bool issFail );
    int  _getPrecision( std::string & precision );
  };


#endif
