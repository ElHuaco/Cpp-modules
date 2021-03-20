/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:58:12 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/20 11:55:17 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include "Tokens.hpp"

namespace my
{
	int		atoi(std::string::const_iterator &it)
	{
		int		result = 0;
		while (isdigit(*it))
		{
			result = result * 10 + *it - '0'; 
			++it;
		}
		--it;
		return (result);
	}
	void	print(Token *token)
	{
		if (token->getType() == "Operand")
			std::cout << "Num(" << dynamic_cast<Operand *>(token)->getNum() << ")";
		else if (token->getType() == "Operator")
			std::cout << "Op(" << dynamic_cast<Operator *>(token)->getSubtype() << ")";
		else
			std::cout << token->getType();
		std::cout << " ";
	}
};

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ex04: error. Argument count must be one." << std::endl;
		return (EXIT_FAILURE);
	}
	std::string input(argv[1]);
	if (input.find_first_not_of("0123456789 -+*/()") != std::string::npos)
	{
		std::cerr << "ex04: error. Infix expression must contain only digits, spaces, '-', '+', '*' and '/'" << std::endl;
		return (EXIT_FAILURE);
	}
	std::deque<Token *>	InfixTokens;
	std::string::const_iterator it = input.begin();
	while (it != input.end())
	{
		if (isdigit(*it))
			InfixTokens.push_back(new Operand(my::atoi(it)));
		else if ((*it == '-') || (*it == '+') || (*it == '*') || (*it == '/'))
			InfixTokens.push_back(new Operator(*it));
		else if (*it == '(')
			InfixTokens.push_back(new ParOpen);
		else if (*it == ')')
			InfixTokens.push_back(new ParClose);
		++it;
	}
	std::cout << "Tokens: ";
	for_each(InfixTokens.begin(), InfixTokens.end(), my::print);
	std::cout << std::endl;
	return(EXIT_SUCCESS);
}
