/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:29:15 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/03/16 11:36:34 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T> class Array
{
	public:
		Array(void) : _size(0)
		{
			this->_elements = new T*[1];
			this->_elements[0] = new T();
			return;
		}
		
		Array(unsigned int size) : _size(size)
		{
			unsigned int	i;
		
			this->_elements = new T*[size];
			i = 0;
			while (i < size)
			{
				this->_elements[i] = new T();
				++i;
			}
			return;
		}
		
		Array(Array const &other)
		{
			*this = other;
			return;
		}
		
		~Array(void)
		{
			unsigned int	i;
		
			i = 0;
			while (i < this->_size)
			{
				delete this->_elements[i];
				++i;
			}
			delete[] this->_elements;
			return;
		}
		
		Array		&operator=(Array const &rhs)
		{
			if (this == &rhs)
				return (*this);
			unsigned int i = 0;
			while (i < this->_size)
			{
				delete this->_elements[i];
				++i;
			}
			delete[] this->_elements;
			this->_elements = new T*[rhs._size];
			i = 0;
			while (i < rhs._size)
			{
				this->_elements[i] = rhs._elements[i];
				++i;
			}
			return (*this);
		}
		
		T				&operator[](unsigned int n)
		{
			if (n >= this->_size)
				throw std::exception();
			return (*(this->_elements[n]));
		}
		
		unsigned int	size(void) const
		{
			return (this->_size);
		}

	private:
		T				**_elements;
		unsigned int	_size;
};
#endif
