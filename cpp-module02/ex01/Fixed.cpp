/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:44:22 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/25 18:18:59 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_num_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_value (0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &that) : _fixed_point_value(that._fixed_point_value)
{
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const n) : _fixed_point_value(n << 8)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const n) :
	_fixed_point_value(roundf(n * (1 << Fixed::_num_fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed		&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed_point_value = rhs.getRawBits();
	return (*this);
}

int			Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void		Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
}

int			Fixed::toInt(void) const
{
	return (this->getRawBits() >> 8);
}

float		Fixed::toFloat(void) const
{
	return (this->getRawBits() / (float)(1 << Fixed::_num_fractional_bits)); 
}

int const	Fixed::getNumFract(void)
{
	return (Fixed::_num_fractional_bits);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs)
{
	os << rhs.getRawBits() / (float)(1 << Fixed::getNumFract());
	return (os);
}
