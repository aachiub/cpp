/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:35:25 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 18:18:44 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequest : public Form {
public:

	RobotomyRequest( std::string const & target );
	RobotomyRequest( RobotomyRequest const & src );
	~RobotomyRequest( void );

	RobotomyRequest & operator = ( RobotomyRequest const & rhs );

	std::string getTarget( void ) const;
	void		setTarget( std::string const & target );

    void        formExecute( void ) const;
 
private:

   };

#endif