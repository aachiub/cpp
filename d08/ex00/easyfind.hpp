/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:54:56 by aachir            #+#    #+#             */
/*   Updated: 2019/01/18 10:14:32 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template< typename T >
bool easyfind(T & container, int  what) {
      for ( typename T::iterator it = container.begin(); it != container.end(); it++ )
        if ( *it == what )
            return ( true );

    return ( false);
} 

#endif
