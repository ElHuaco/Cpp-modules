/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:08:08 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/17 12:47:08 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void) : std::vector<int>::vector<int>()
{
	return;
}

Span::Span(unsigned int N) : std::vector<int>::vector<int>(),
	_nCalls(0), _nCallsMax(N)
{
	return;
}

Span::~Span(void)
{
	return;
}

void		Span::addNumber(int const &number)
{
	if (this->_nCalls >= this->_nCallsMax)
		throw std::out_of_range("Error: out of range");
	this->push_back(number);
	this->_nCalls += 1;
	return;
}

void		Span::addNumber(unsigned int const &number)
{
	unsigned int	i = 0;

	while (i < number)
	{
		if (this->_nCalls >= this->_nCallsMax)
			throw std::out_of_range("Error: out of range");
		this->push_back(rand() % 1000000 - 500000);
		this->_nCalls += 1;
		++i;
	}
	return;
}

const char	*Span::NoSpanToFindException::what(void) const throw()
{
	return ("Error: no span to find.");
}

int			Span::shortestSpan(void) const
{
	if (this->_nCalls <= 1)
		throw Span::NoSpanToFindException();
	return (0);
}

int			Span::longestSpan(void) const
{
	if (this->_nCalls <= 1)
		throw Span::NoSpanToFindException();
	return (*max_element(this->begin(), this->end())
			-*min_element(this->begin(), this->end()));
}
