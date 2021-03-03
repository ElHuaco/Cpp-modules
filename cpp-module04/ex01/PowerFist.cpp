/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:35:45 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:53:46 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist(PowerFist const &rhs) : AWeapon(rhs)
{
	return;
}

PowerFist::~PowerFist(void)
{
	return;
}

PowerFist		&PowerFist::operator=(PowerFist const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return (*this);
}

void			PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
	return;
}
