/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:30:59 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 10:21:06 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const &rhs)
{
	*this = rhs;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead.";
	std::cout << " Consequences will never be the same!" << std::endl;
	return;
}

Sorcerer	&Sorcerer::operator=(Sorcerer const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_title = rhs._title;
	return (*this);
}

void		Sorcerer::setName(std::string name)
{
	this->_name = name;
	return;
}

void		Sorcerer::setTitle(std::string title)
{
	this->_title = title;
	return;
}

std::string	Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string	Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void		Sorcerer::polymorph(Victim const &target) const
{
	target.getPolymorphed();
	return;
}

std::ostream	&operator<<(std::ostream &os, Sorcerer const &rhs)
{
	os << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies!";
	os << std::endl;
	return (os);
}
