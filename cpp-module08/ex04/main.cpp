/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:58:12 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/20 13:20:34 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
#include <exception>
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

static void		checkParenthError(Token *token)
{
	if ((token->getType() == "ParOpen") || (token->getType() == "ParClose"))
		throw std::invalid_argument("ex04: error. Wrong parenthesis use");
	return;
}

std::ostream	&operator<<(std::ostream &os, std::stack<int> postStack)
{
	while (postStack.empty() == false)
	{
		os << postStack.top() << " ";
		postStack.pop();
	}
	return (os);
}

static int		operation(int a, int b, char type)
{
	return ((type == '+') * (b + a) + (type == '-') * (b - a)
		+ (type == '*') * (b * a) + (type == '/') * (b / a));
}

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
/*	TOKEN CONSTRUCTION */
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
/*	INFIX TO POSTFIX ALGORITHM */
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
				if (TempStack.empty() == true)
					throw std::invalid_argument("ex04: error. Wrong parenthesis use");
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
	for_each(PostfixTokens.begin(), PostfixTokens.end(), checkParenthError);
	for_each(PostfixTokens.begin(), PostfixTokens.end(), my::print);
	std::cout << std::endl;
/*	COMPUTE USING THE RESULTING STACK */
	std::stack<int>	resultStack;
	std::deque<Token *>::const_iterator itpost = PostfixTokens.begin();
	int temp1;
	int temp2;
	while (itpost != PostfixTokens.end())
	{
		if ((*itpost)->getType() == "Operand")
		{
			std::cout << "I Num(" << dynamic_cast<Operand *>(*itpost)->getNum() << ") | OP Push | ";
			resultStack.push(dynamic_cast<Operand *>(*itpost)->getNum());
			std::cout << "ST " << resultStack << "]" << std::endl;
		}
		else
		{
			if (resultStack.size() < 2)
				throw std::invalid_argument("ex04: error. Wrong expression.");
			std::cout << "I " << (*itpost)->getType() << " | OP ";
			std::cout << dynamic_cast<Operator *>(*itpost)->getSubtype() << " | ";
			temp1 = resultStack.top();
			resultStack.pop();
			temp2 = resultStack.top();
			resultStack.pop();
			resultStack.push(operation(temp1, temp2, dynamic_cast<Operator *>(*itpost)->getSubtype()));
			std::cout << "ST " << resultStack << "]" << std::endl;
		}
		++itpost;
	}
	std::cout << "Result: " << resultStack.top() << std::endl;
	return(EXIT_SUCCESS);
}
