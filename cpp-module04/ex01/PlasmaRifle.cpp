/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:27:00 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:54:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &rhs) : AWeapon(rhs)
{
	return;
}

PlasmaRifle::~PlasmaRifle(void)
{
	return;
}

PlasmaRifle		&PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return (*this);
}

void			PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
	return;
}
