/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:11:32 by aachir            #+#    #+#             */
/*   Updated: 2019/01/16 15:27:00 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialization.hpp"

int main( void )
{
	Serialization 	s;

	void * pSerial = s.serialize();
	if ( ! pSerial )
		return (1 );

	Data * pDeserial = s.deserialize( pSerial );
	if ( ! pDeserial )
		return (1 );

	std::cout << "---> Serialization / deserialization" << std::endl;
	std::cout << "\ts1: " << pDeserial->s1 << std::endl << "\tn : " << pDeserial->n << std::endl \
														<< "\ts2: " << pDeserial->s2 << std::endl;

	delete reinterpret_cast<DataOnHeap*>( pSerial );
	delete pDeserial;

}

