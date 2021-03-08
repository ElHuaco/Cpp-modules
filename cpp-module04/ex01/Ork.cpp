/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ork.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:32:45 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:33:50 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ork.hpp"

Ork::Ork(void) : Enemy(100, "Ork")
{
	std::cout << "WAAAGH!" << std::endl;
	return;
}

Ork::Ork(Ork const &rhs) : Enemy(rhs)
{
	std::cout << "WAAAGH!" << std::endl;
	return;
}

Ork::~Ork(void)
{
	std::cout << "NOoOoOoo..." << std::endl;
	return;
}

Ork		&Ork::operator=(Ork const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setType(rhs.getType());
	this->setHP(rhs.getHP());
	return (*this);
}
