/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:35:02 by aachir            #+#    #+#             */
/*   Updated: 2019/01/15 18:02:08 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardon : public Form {
public:

	PresidentialPardon( std::string const & target );
	PresidentialPardon( PresidentialPardon const & src );
	~PresidentialPardon( void );

	PresidentialPardon & operator = ( PresidentialPardon const & rhs );

	std::string getTarget( void ) const;
	void		setTarget( std::string const & target );

    void        formExecute( void ) const;

private:

	
    };

#endif
