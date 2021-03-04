/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:24:14 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 09:17:55 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) : _faith(40000)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	return;
}

TacticalMarine::TacticalMarine(TacticalMarine const &other)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	*this = other;
	return;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh..." << std::endl;
	return;
}

TacticalMarine		&TacticalMarine::operator=(TacticalMarine const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_faith = rhs._faith;
	return (*this);
}

ISpaceMarine		*TacticalMarine::clone(void) const
{
	ISpaceMarine *recruit = new TacticalMarine;
	*recruit = *this;
	return (recruit);
}

void				TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!" << std::endl;
	return;	
}

void				TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *" << std::endl;
	return;
}

void				TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
	return;
}
