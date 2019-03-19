/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:11:58 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 15:11:59 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include "Classes.hpp"

class Identify {

public:
    Identify( void );
    Identify( Identify const & src );
    ~Identify( void );
    Identify & operator = ( Identify const & rhs );

    t_classIndex byPointer( Base * p );
    t_classIndex byReference( Base & p );

private:
};


#endif

