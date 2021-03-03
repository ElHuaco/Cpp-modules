/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:56:48 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:52:29 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
	std::cout << "*click click click*" << std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion const &rhs) : Enemy(rhs)
{
	std::cout << "*click click click*" << std::endl;
	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

RadScorpion		&RadScorpion::operator=(RadScorpion const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setType(rhs.getType());
	this->setHP(rhs.getHP());
	return (*this);
}
