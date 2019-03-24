/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachir <aachir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:50:12 by aachir            #+#    #+#             */
/*   Updated: 2019/03/24 14:04:36 by aachir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// static member functions

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	if (Account::getNbAccounts())
	{
		Account::_displayTimestamp();
		std::cout << "accounts:" << Account::getNbAccounts() \
				<< ";total:" << Account::getTotalAmount() \
				<< ";deposits:" << Account::getNbDeposits() \
				<< ";withdrawals:" << Account::getNbWithdrawals()\
				<< std::endl;
	}
}

void	Account::_displayTimestamp( void )
{
  	time_t		now;
    char		dt[20];
	struct tm	*loctime;
	
  	now = time(NULL);
	loctime = localtime(&now);
	strftime(dt, sizeof(dt), "[%Y%m%d_%H%M%S] ", loctime);
	std::cout << dt;
}

// non static member functions

Account::Account( int initial_deposit )
{
	
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbCheckAmount = 0;
	Account::_totalAmount += this->_amount;
	++Account::_nbAccounts;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << "amount:" << this->_amount \
				 << ";created" << std::endl;
}

Account::Account( void )
{
	Account::Account(0);
}

Account::~Account( void )
{
	--Account::_nbAccounts;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			<< ";amount:" << this->_amount \
			<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			<< ";p_amount:" << this->_amount \
			<< ";deposit:" << deposit \
			<< ";amount:" << (this->_amount + deposit) \
			<< ";nb_deposits:" << ++this->_nbDeposits \
			<< std::endl;


	this->_amount += deposit;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			<< ";p_amount:" << this->_amount \
			<< ";withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	std::cout << withdrawal << ";amount:" << (this->_amount - withdrawal) \
			<< ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;

	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	return true;
}

int		Account::checkAmount( void ) const
{
	++const_cast<Account *>(this)->_nbCheckAmount;
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			<< ";amount:" << this->_amount \
			<< ";deposits:" << this->_nbDeposits \
			<< ";withdrawals:" << this->_nbWithdrawals \
			<< std::endl;

}
