/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:56:22 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/18 12:08:22 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>::std::stack()
{
	return;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other) :
	std::stack<T>::std::stack(other)
{
	return;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	return;
}

template <typename T>
class MutantStack<T>		&MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
	MutantStack<T> temp(rhs);
	std::swap(*this, temp);
	return (*this);
}

template <typename T>
MutantStack<T>::iterator::iterator(void)
	: std::iterator<std::bidirectional_iterator_tag, T>::iterator()
	  , _ptr(nullptr)
{
	return;
}

template <typename T>
MutantStack<T>::iterator::iterator(iterator const &other)
	: std::iterator<std::bidirectional_iterator_tag, T>::iterator(other)
	  , _ptr(other._ptr)
{
	return;
}

template <typename T>
MutantStack<T>::iterator::~iterator(void)
{
	return;
}

template <typename T>
class MutantStack<T>::iterator	&MutantStack<T>::iterator::operator=(MutantStack<T>::iterator const &rhs)
{
	iterator temp(rhs);
	std::swap(*this, temp);
	return (*this);
}

template <typename T>
class MutantStack<T>::iterator	&MutantStack<T>::iterator::operator=(T *ptr)
{
	this->_ptr = ptr;
	return (*this);
}

template <typename T>
bool		MutantStack<T>::iterator::operator==(const MutantStack<T>::iterator &rhs) const
{
	return ((rhs._ptr == this->_ptr) ? true : false);
}

template <typename T>
bool		MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator &rhs) const
{
	return ((rhs._ptr == this->_ptr) ? false : true);
}

template <typename T>
T			&MutantStack<T>::iterator::operator*(void) const
{
	return (*this->_ptr);
}

template <typename T>
class MutantStack<T>::iterator	&MutantStack<T>::iterator::operator++(void)
{
	++(this->_ptr);
	return (*this);
}

template <typename T>
class MutantStack<T>::iterator	&MutantStack<T>::iterator::operator--(void)
{
	--(this->_ptr);
	return (*this);
}

template <typename T>
class MutantStack<T>::iterator	MutantStack<T>::iterator::operator++(int)
{
	iterator temp(*this);
	++(this->_ptr);
	return (temp);
}

template <typename T>
class MutantStack<T>::iterator	MutantStack<T>::iterator::operator--(int)
{
	iterator temp(*this);
	--(this->_ptr);
	return (temp);
}

template <typename T>
class MutantStack<T>::iterator	&MutantStack<T>::begin(void) const
{
	iterator first;
	first->_ptr = &this->top();
	std::advance(first, -1 * this->size() + 1);
	return (first);
}

template <typename T>
class MutantStack<T>::iterator	&MutantStack<T>::end(void) const
{
	iterator last;
	last->_ptr = &this->top();
	return (last);
}
#include "mutantstack.hpp"
