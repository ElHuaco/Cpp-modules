/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:51:17 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 10:21:52 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void) : _name(nullptr)
{
	return;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called  " << this->_name << " just appeared!" << std::endl;
	return;
}

Victim::Victim(Victim const &rhs)
{
	*this = rhs;
	std::cout << "Some random victim called  " << this->_name << " just appeared!" << std::endl;
	return;
}

Victim::~Victim(void)
{

	std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
	return;
}

Victim			&Victim::operator=(Victim const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	return (*this);
}

void		Victim::setName(std::string name)
{
	this->_name = name;
	return;
}

std::string	Victim::getName(void) const
{
	return (this->_name);
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
	return;
}

std::ostream	&operator<<(std::ostream &os, Victim const &rhs)
{
	os << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return (os);
}
