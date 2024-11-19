/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:06:24 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/19 19:28:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts 			= 0;
int	Account::_totalAmount 			= 0;
int	Account::_totalNbDeposits 		= 0;
int	Account::_totalNbWithdrawals	= 0;

// Constructor
Account::Account( int initial_deposit ){
	_accountIndex		= _nbAccounts;
	_amount				= initial_deposit;
	_nbDeposits			= 0;
	_nbWithdrawals		= 0;

	_nbAccounts++;
	_totalAmount += this->_amount;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

// Destructor
Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ){
	time_t	timestamp = time(&timestamp);
	struct	tm datetime = *localtime(&timestamp);

	std::cout << "[";
	std::cout << datetime.tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << datetime.tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << datetime.tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << datetime.tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << datetime.tm_min;
	std::cout << std::setw(2) << std::setfill('0') << datetime.tm_sec;
	std::cout << "] ";
}

// Getters
int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
