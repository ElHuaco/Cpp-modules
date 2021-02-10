/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:25:12 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/10 12:14:01 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 0;
		while (argv[++i] != NULL)
		{	
			std::string str = argv[i];
			std::string::size_type j = -1;
			while (++j < str.length())
			{
				if (std::isalpha(str[j]))
					std::cout << (char)std::toupper(str[j]);
				else if (str[j] != '"')
					std::cout << (char)str[j];
				else
					continue;
			}
			std::cout << (char)' ';
		}
		std::cout << std::endl;
	}
	return (0);
}
