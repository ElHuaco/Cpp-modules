/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:27:49 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/17 12:57:27 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"
#include <string>
#include <iostream>

static void	search_contact_in_phonebook(contact *phonebook)
{
	int			i;
	//Print contenidos phonebook;
	std::cout << "SELECT INDEX FOR CONTACT INFO: ";
	std::cin << i;
	if ((i < 1) || (i > 8))
		return ;
	phonebook[i - 1].display_info();
	return ;
}

static void	add_contact_to_phonebook(contact *phonebook)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (!phonebook[i].first_name.compare(""))
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
