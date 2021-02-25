/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:44:22 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/25 18:55:08 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_num_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_value (0)
{
	return;
}

Fixed::Fixed(Fixed const &that) : _fixed_point_value(that._fixed_point_value)
{
	return;
}

Fixed::Fixed(int const n) : _fixed_point_value(n << 8)
{
	return;
}

Fixed::Fixed(float const n) :
	_fixed_point_value(roundf(n * (1 << Fixed::_num_fractional_bits)))
{
	return;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed		&Fixed::operator=(Fixed const &rhs)
{
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

bool		Fixed::operator>(Fixed const &rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator<(Fixed const &rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator>=(Fixed const &rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator<=(Fixed const &rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator==(Fixed const &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator!=(Fixed const &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (false);
	else
		return (true);
}

Fixed		Fixed::operator+(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed		Fixed::operator-(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed		Fixed::operator*(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() * rhs.getRawBits());
	return (result);
}

Fixed		Fixed::operator/(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() / rhs.getRawBits());
	return (result);
}

Fixed		&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed		&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed		&Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed		&Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

Fixed const		&Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

Fixed const		&Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}
