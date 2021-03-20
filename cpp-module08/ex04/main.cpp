/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:58:12 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/20 12:38:13 by alejandro        ###   ########.fr       */
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
		std::cerr << "ex04: error. Infix expression must contain only digits, spaces, '-', '+', '*', '/' and parenthesis." << std::endl;
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
	std::stack<Token *> TempStack;
	std::deque<Token *> PostfixTokens;
	std::deque<Token *>::const_iterator i = InfixTokens.begin();
	while (i != InfixTokens.end())
	{
		if ((*i)->getType() == "Operand")
			PostfixTokens.push_back(*i);
		else if ((*i)->getType() == "Operator")
		{
			while ((TempStack.empty() == false)
				&& (TempStack.top()->getType() != "ParOpen")
				&& (dynamic_cast<Operator *>(TempStack.top())->getPrecedence() >=
					dynamic_cast<Operator *>(*i)->getPrecedence()))
			{
				PostfixTokens.push_back(TempStack.top());
				TempStack.pop();
			}
			TempStack.push(*i);
		}
		else if ((*i)->getType() == "ParOpen")
			TempStack.push(*i);
		else if ((*i)->getType() == "ParClose")
		{
			while (TempStack.top()->getType() != "ParOpen")
			{
				PostfixTokens.push_back(TempStack.top());
				TempStack.pop();
			}
			TempStack.pop();
		}
		++i;
	}
	while (TempStack.empty() == false)
	{
		PostfixTokens.push_back(TempStack.top());
		TempStack.pop();
	}
	std::cout << "Postfix: ";
	for_each(PostfixTokens.begin(), PostfixTokens.end(), my::print);
	std::cout << std::endl;
	return(EXIT_SUCCESS);
}
