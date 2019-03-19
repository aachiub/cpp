/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:35:31 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 18:20:31 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreation : public Form {
public:

	ShrubberyCreation( std::string const & target );
	ShrubberyCreation( ShrubberyCreation const & src );
	~ShrubberyCreation( void );

	ShrubberyCreation & operator = ( ShrubberyCreation const & rhs );

	std::string getTarget( void ) const;
	void		setTarget( std::string const & target );

    void        formExecute( void ) const;

private:
	
    };

#endif