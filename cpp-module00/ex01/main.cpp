/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:27:49 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 08:42:42 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"
#include <string>
#include <iostream>
#include <iomanip>

static void	search_contact_in_phonebook(contact *phonebook)
{
	int			i;
	std::string	j;

	std::cout.setf(std::ios::right, std::ios::adjustfield);
	i = -1;
	while ((++i < 8) && (phonebook[i].get_first_name().compare("") != 0))
	{
		std::cout << std::setw(10);
		std::cout << (int)(i + 1) << "|";
		phonebook[i].display_short_info();
	}
	std::cout.unsetf(std::ios::adjustfield);
	std::cout << "SELECT INDEX FOR CONTACT INFO: ";
	std::cin >> j;
	if ((j.size() != 1) || !(isdigit(j[0])) || (j[0] < '1')
		|| (j[0] > '8') || (j[0] > i + '0'))
		return ;
	phonebook[j[0] - '0' - 1].display_info();
	return ;
}

static void	add_contact_to_phonebook(contact *phonebook)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (!phonebook[i].get_first_name().compare(""))
		{
			phonebook[i].fill_info();
			break;
		}
	}
	if (i == 8)
		std::cout << "PHONEBOOK IS FULL" << std::endl;
	return ;
}

int		main(void)
{
	std::string cmd;
	contact		phonebook[8];

	while (1)
	{
		std::cout << "ENTER COMMAND: ";
		std::cin >> cmd;
		if (!(cmd.compare("EXIT")))
			return (0);
		else if (!(cmd.compare("SEARCH")))
			search_contact_in_phonebook(phonebook);
		else if (!(cmd.compare("ADD")))
			add_contact_to_phonebook(phonebook);
		else
			std::cout << cmd << " COMMAND NOT FOUND" << std::endl;
		cmd.clear();
	}
}
