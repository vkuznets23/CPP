/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:25:45 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/04 11:45:49 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*creates a new account with initial deopis as amount
 *init the values to deposits and withdraws
 *print out timestamp, index, amount, "created"
 *remember to update nbaccounts and total amount
 [19920104_091532] index:0;amount:42;created
 */
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

/*displat timestamp, index, amount, "closed"
 * [19920104_091532] index:0;amount:47;closed
 */
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

//functions to access the object values
int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

/*const keyword on function name(?) guarantees not to modify the state of the object*/
int	Account::checkAmount() const
{
	return _amount;
}

/*display number of accounts total deposits and withdrawals
 * message looks like this
 * Timestamp accounts:NUM;total:NUM;deposits:NUM;withdrawals:NUM
 * [19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
 */
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

/*same as above but for the current object
 * Example
 * [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
 */
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

/*amount + deposit
 *deposist and total deposits and total amount go up
 *[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
 */
void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount - deposit
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

/*if withdraw > amount
 * 	[19920104_091532] index:5;p_amount:23;withdrawal:refused
 * 	return false
 * else
 * 	[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
 * 	amount - withdraw
 * 	withdraws , total withdraws up, total down
 * 	retunr true
 */
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused" << std::endl;
		return false;
	} else {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount + withdrawal
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawal:" << _nbWithdrawals
			<< std::endl;
		return true;
	}
	
}

//dipslay time stamp
void Account::_displayTimestamp()
{
	std::time_t currentTime = std::time(NULL);
	char buffer[20];

	// Format the timestamp as "YYYYMMDD_HHMMSS"
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&currentTime));
	std::cout << "[" << buffer << "] ";
}
