/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:10:07 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 11:35:09 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void		HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return;
}

void		HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with ";
	std::cout << this->_weapon->getType() << std::endl;
	return;
}
