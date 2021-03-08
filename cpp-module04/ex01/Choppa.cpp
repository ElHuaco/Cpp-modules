/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Choppa.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:34:46 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:35:26 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Choppa.hpp"

Choppa::Choppa(void) : AWeapon("Choppa", 4, 25)
{
	return;
}

Choppa::Choppa(Choppa const &rhs) : AWeapon(rhs)
{
	return;
}

Choppa::~Choppa(void)
{
	return;
}

Choppa		&Choppa::operator=(Choppa const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return (*this);
}

void			Choppa::attack(void) const
{
	std::cout << "* CHOP! *" << std::endl;
	return;
}
