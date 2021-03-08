/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ork.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:14:41 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:16:06 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ork.hpp"

Ork::Ork(void) : Victim()
{
	return;
}

Ork::Ork(std::string name) : Victim(name)
{
	std::cout << "Ork iz best!" << std::endl;
	return;
}

Ork::Ork(Ork const &rhs) : Victim(rhs)
{
	std::cout << "Ork iz best!" << std::endl;
	return;
}

Ork::~Ork(void)
{
	std::cout << "Me wazznot da Greenest..." << std::endl;
	return;
}

Ork			&Ork::operator=(Ork const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	return (*this);
}

void			Ork::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a green pony!" << std::endl;
	return;
}
