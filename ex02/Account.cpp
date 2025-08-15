/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:10:59 by fredchar          #+#    #+#             */
/*   Updated: 2025/08/15 03:44:42 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>


Account::Account(int inital_deposit)
	: _accountIndex(_nbAccounts),
	_amount(inital_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += inital_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;

}	

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(nullptr);
	std::tm *ltm = std::localtime(&now);

	std::cout	<< '['
				<< (ltm->tm_year + 1990)
				<< std::setw(2) << std::setfill('0') << (ltm->tm_mon + 1)
				<< std::setw(2) << std::setfill('0') << ltm->tm_mday << '_'
				<< std::setw(2) << std::setfill('0') << ltm->tm_hour
				<< std::setw(2) << std::setfill('0') << ltm->tm_min
				<< std::setw(2) << std::setfill('0') << ltm->tm_sec
				<< "] ";
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit." << deposit;

	_amount += deposit;
	_nbDeposits++;

	_totalNbDeposits++;
	_totalAmount += deposit;

	std::cout << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal 
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}