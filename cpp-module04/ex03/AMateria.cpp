/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:48:29 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 15:56:34 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	return;
}

AMateria::AMateria(std::string const &type) : _xp(0), _type(type)
{
	return;
}

AMateria::AMateria(AMateria const &other)
{
	*this = other;
	return;
}

AMateria::~AMateria(void)
{
	return;
}

AMateria		&AMateria::operator=(AMateria const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_xp = rhs._xp;
	this->_type = rhs._type;
	return (*this);
	return;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->_xp);
}
