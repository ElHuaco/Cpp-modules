/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:08:08 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/20 13:32:13 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

Span::Span(unsigned int N) : std::vector<int>::vector<int>(),
	_nCalls(0), _nCallsMax(N)
{
	return;
}

Span::~Span(void)
{
	return;
}

Span::Span(Span const &other) : std::vector<int>::vector<int>(other),
	_nCalls(other._nCalls), _nCallsMax(other._nCallsMax)
{
	return;
}

Span		&Span::operator=(Span const &rhs)
{
	Span temp(rhs);
	std::swap(*this, temp);
	return (*this);
}

void		Span::addNumber(int const &number)
{
	if (this->_nCalls >= this->_nCallsMax)
		throw std::out_of_range("Error: out of range");
	this->push_back(number);
	this->_nCalls += 1;
	return;
}

void		Span::addNumber(int from, int to)
{
	while (from <= to)
	{
		if (this->_nCalls >= this->_nCallsMax)
			throw std::out_of_range("Error: out of range");
		this->push_back(rand() % INT_MAX);
		this->_nCalls += 1;
		++from;
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
	std::vector<int> copy(*this);
	std::sort(copy.begin(), copy.end());
	int	diff;
	int	shortest = INT_MAX;
	std::vector<int>::const_iterator first = copy.begin();
	while (first != copy.end() - 1)
	{
		diff = std::abs(first[0] - first[1]);
		if (diff < shortest)
			shortest = diff;
		++first;
	}
	return (shortest);
}

int			Span::longestSpan(void) const
{
	if (this->_nCalls <= 1)
		throw Span::NoSpanToFindException();
	return (*max_element(this->begin(), this->end())
			-*min_element(this->begin(), this->end()));
}
