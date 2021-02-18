/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:36:51 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/18 09:55:15 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ContactClass.hpp"

contact::contact(void)
{
	return;
}

contact::~contact(void)
{
	return;
}

void		contact::fill_info(void)
{
	std::cin.ignore();
	std::cout << "First name: ";
	std::getline(std::cin, this->first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, this->last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Login: ";
	std::getline(std::cin, this->login);
	std::cout << "Postal address: ";
	std::getline(std::cin, this->postal_address);
	std::cout << "e-mail address: ";
	std::getline(std::cin, this->email_address);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phone_number);
	std::cout << "Birthday date: ";
	std::getline(std::cin, this->birthday_date);
	std::cout << "Favorite meal: ";
	std::getline(std::cin, this->favorite_meal);
	std::cout << "Underwear color: ";
	std::getline(std::cin, this->underwear_color);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->darkest_secret);
	return ;
}

void		contact::display_info(void) const
{
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->login << std::endl;
	std::cout << this->postal_address << std::endl;
	std::cout << this->email_address << std::endl;
	std::cout << this->phone_number << std::endl;
	std::cout << this->birthday_date << std::endl;
	std::cout << this->favorite_meal << std::endl;
	std::cout << this->underwear_color << std::endl;
	std::cout << this->darkest_secret << std::endl;
	return ;
}

static void display_short_info_str(std::string str)
{
	if (str.size() > 10)
	{
		std::cout << std::setw(9);
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void		contact::display_short_info(void) const
{
	display_short_info_str(this->first_name);
	std::cout << "|";
	display_short_info_str(this->last_name);
	std::cout << "|";
	display_short_info_str(this->nickname);
	std::cout << std::endl;
	return ;
}
