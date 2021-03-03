/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:05:54 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 10:18:31 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(void) : Victim()
{
	return;
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(Peon const &rhs) : Victim(rhs)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

Peon			&Peon::operator=(Peon const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->getName() = rhs.getName();
	return (*this);
}

void			Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
	return;
}
