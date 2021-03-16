/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:29:15 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/03/16 12:29:29 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T> class Array
{
	private:
		T				*_elements;
		unsigned int	_size;

	public:
		Array(void) : _size(0)
		{
			this->_elements = new T[1];
			return;
		}
		
		Array(unsigned int size) : _size(size)
		{
			this->_elements = new T[size];
			return;
		}
		
		Array(Array const &other)
		{
			this->_elements = new T[1];
			*this = other;
			return;
		}
		
		~Array(void)
		{
			delete[] this->_elements;
			return;
		}
		
		Array		&operator=(Array const &rhs)
		{
			if (this == &rhs)
				return (*this);
			delete[] this->_elements;
			this->_size = rhs._size;
			this->_elements = new T[rhs._size];
			unsigned int i = 0;
			while (i < rhs._size)
			{
				this->_elements[i] = T(rhs._elements[i]);
				++i;
			}
			return (*this);
		}

		T				&operator[](unsigned int n)
		{
			if (n >= this->_size)
				throw std::exception();
			return (this->_elements[n]);
		}
		
		unsigned int	size(void) const
		{
			return (this->_size);
		}
};
#endif
