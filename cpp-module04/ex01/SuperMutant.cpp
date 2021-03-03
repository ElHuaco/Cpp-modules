/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:50:14 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:49:53 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const &rhs) : Enemy(rhs)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh..." << std::endl;
	return;
}

SuperMutant		&SuperMutant::operator=(SuperMutant const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setType(rhs.getType());
	this->setHP(rhs.getHP());
	return (*this);
}

void		SuperMutant::takeDamage(int amount)
{
	amount -= 3;
	if (amount <= 0)
		return;
	if (this->getHP() <= amount)
		this->setHP(0);
	else
		this->setHP(this->getHP() - amount);
	return;
}
