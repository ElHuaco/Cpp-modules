/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:34:09 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 09:00:32 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void) : _faith(40000)
{
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &other)
{
	std::cout << "* teleports from space *" << std::endl;
	*this = other;
	return;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back..." << std::endl;
	return;
}

AssaultTerminator		&AssaultTerminator::operator=(AssaultTerminator const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_faith = rhs._faith;
	return (*this);
}

ISpaceMarine		*AssaultTerminator::clone(void) const
{
	AssaultTerminator *recruit = new AssaultTerminator;
	*recruit = *this;
	return (recruit);
}

void				AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
	return;	
}

void				AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
	return;
}

void				AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
	return;
}
