/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:38:43 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/19 19:52:18 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <string>
#include <ctime>

int			Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int			Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int			Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int			Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void		Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << std::to_string(Account::getNbAccounts());
	std::cout << ";total:" << std::to_string(Account::getTotalAmount());
	std::cout << ";deposits:" << std::to_string(Account::getNbDeposits());
	std::cout << ";withdrawals:" << std::to_string(Account::getNbWithdrawals());
	std::cout << std::endl;
	return;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";amount:" << std::to_string(this->_amount);
	std::cout << ";created" << std::endl;
	return;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ';' << "amount:" << std::to_string(this->_amount);
	std::cout << ";closed" << std::endl;
	return;
}

void		Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";p_amount:" << std::to_string(this->_amount);
	std::cout << ";deposit:" << std::to_string(deposit);
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << std::to_string(this->_amount);
	std::cout << ";nb_deposits:" << std::to_string(this->_nbDeposits);
	std::cout << std::endl;
	return;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";p_amount:" << std::to_string(this->_amount);
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << ";withdrawal:" << std::to_string(withdrawal);
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << ";amount:" << std::to_string(this->_amount);
		std::cout << ";nb_withdrawals:" << std::to_string(this->_nbWithdrawals);
		std::cout << std::endl;
		return (true);
	}
}

int			Account::checkAmount(void) const
{
	return (1);
}

void		Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";amount:" << std::to_string(this->_amount);
	std::cout << ";deposits:" << std::to_string(this->_nbDeposits);
	std::cout << ";withdrawals:" << std::to_string(this->_nbWithdrawals);
	std::cout << std::endl;
	return;
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

void		Account::_displayTimestamp(void)
{
	std::time_t		now;
	struct std::tm	ts;
	char			time_formated[18];
	int				i;

	std::time(&now);
	ts = *localtime(&now);
	std::strftime(time_formated, 18 * sizeof(char), "[%Y%m%d_%H%M%S] ",
		&ts);
	i = -1;
	while (++i != 18)
		std::cout << time_formated[i];
}

Account::Account(void)
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
