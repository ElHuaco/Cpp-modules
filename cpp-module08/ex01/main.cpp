/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:51:34 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/17 12:43:04 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

# define SIZE1 3
# define SIZE2 10000

static void	print(int const &number)
{
	std::cout << number << std::endl;
	return;
}

int		main(void)
{
	srand(time(NULL));
	std::cout << "===========Span Class constructor=============" << std::endl;
	Span  S1(SIZE1);
	for_each(S1.begin(), S1.end(), print);
	std::cout << std::endl;
	std::cout << "========Correct simple addNumber use==========" << std::endl;
	S1.addNumber(static_cast<int>(rand() % 10 - 5));
	S1.addNumber(static_cast<int>(rand() % 10 - 5));
	S1.addNumber(static_cast<int>(rand() % 10 - 5));
	for_each(S1.begin(), S1.end(), print);
	std::cout << "Shortest: " << S1.shortestSpan() << std::endl;
	std::cout << "Longest: " << S1.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "========Correct multiple addNumber use========" << std::endl;
	Span  S2(SIZE2);
	S2.addNumber(static_cast<unsigned int>(SIZE2));
	std::cout << "Shortest: " << S2.shortestSpan() << std::endl;
	std::cout << "Longest: " << S2.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "=======Incorrect simple addNumber use=========" << std::endl;
	try
	{
		S1.addNumber(static_cast<int>(rand() % 10 - 10));
	}
	catch (std::out_of_range &oor)
	{
		std::cout << oor.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "======Incorrect multiple addNumber use========" << std::endl;
	try
	{
		S2.addNumber(static_cast<unsigned int>(SIZE2));
	}
	catch (std::out_of_range &oor)
	{
		std::cout << oor.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=====Incorrect shortest(longest) span use=====" << std::endl;
	Span	S3(1);
	try
	{
		S3.shortestSpan();
	}
	catch (Span::NoSpanToFindException &e)
	{
		std::cout << e.what() << std::endl;
	}
	S3.addNumber(static_cast<int>(1));
	try
	{
		S3.longestSpan();
	}
	catch (Span::NoSpanToFindException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
