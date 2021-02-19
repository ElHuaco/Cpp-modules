/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:38:43 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/19 14:03:30 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <string>
#include <ctime>

int		_totalAmount = 0;
int		_nbAccounts = 0;
int		_totalNbDeposits = 0;
int		_totalNbWithdrawals = 0;

void		_displayTimestamp(void)
{
	std::cout << "[202102";
	//Día
	std::cout << "_";
	//segundos del día
	std::cout << " ";
}

Account::Account(int amount)
	: initial_deposit(amount)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = this->initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->initial_deposit;
	_displayTimestamp();
	std::cout << ' ' << "index:" << std::to_string(this->_accountIndex);
	std::cout << ';' << "amount:" << std::to_string(this->_amount);
	std::cout << ";created" << std::endl;
	return;
}


void		Account::displayAccountInfos(void)
{
	std::cout << 
}
