/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:36:51 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 08:42:29 by aleon-ca         ###   ########.fr       */
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
	std::getline(std::cin, this->_first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, this->_last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Login: ";
	std::getline(std::cin, this->_login);
	std::cout << "Postal address: ";
	std::getline(std::cin, this->_postal_address);
	std::cout << "e-mail address: ";
	std::getline(std::cin, this->_email_address);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->_phone_number);
	std::cout << "Birthday date: ";
	std::getline(std::cin, this->_birthday_date);
	std::cout << "Favorite meal: ";
	std::getline(std::cin, this->_favorite_meal);
	std::cout << "Underwear color: ";
	std::getline(std::cin, this->_underwear_color);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->_darkest_secret);
	return ;
}

void		contact::display_info(void) const
{
	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_login << std::endl;
	std::cout << this->_postal_address << std::endl;
	std::cout << this->_email_address << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_birthday_date << std::endl;
	std::cout << this->_favorite_meal << std::endl;
	std::cout << this->_underwear_color << std::endl;
	std::cout << this->_darkest_secret << std::endl;
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
	display_short_info_str(this->_first_name);
	std::cout << "|";
	display_short_info_str(this->_last_name);
	std::cout << "|";
	display_short_info_str(this->_nickname);
	std::cout << std::endl;
	return ;
}

std::string	contact::get_first_name(void) const
{
	return (this->_first_name);
}
