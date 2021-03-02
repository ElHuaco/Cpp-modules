/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:36:33 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 11:38:15 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

void		SuperTrap::setInitialValues(void)
{
	this->setHP(100);
	this->setMaxHP(100);
	this->setEP(120);
	this->setMaxEP(120);
	this->setLevel(1);
	this->setMeleeDMG(60);
	this->setRangedDMG(15);
	this->setArmor(5);
	return;
}

SuperTrap::SuperTrap(void) : ClapTrap()
{
	std::cout << "Default SUP-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name)
{
	std::cout << "String SUP-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

SuperTrap::SuperTrap(SuperTrap const &rhs)
{
	std::cout << "Copy SUP-TP constructor called" << std::endl;
	*this = rhs;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUP-TP Destructor called" << std::endl;
	return;
}

SuperTrap	&SuperTrap::operator=(SuperTrap const &rhs)
{
	this->setName(rhs.getName());
	this->setHP(rhs.getHP());
	this->setMaxHP(rhs.getMaxHP());
	this->setEP(rhs.getEP());
	this->setMaxEP(rhs.getMaxEP());
	this->setLevel(rhs.getLevel());
	this->setMeleeDMG(rhs.getMeleeDMG());
	this->setRangedDMG(rhs.getRangedDMG());
	this->setArmor(rhs.getArmor());
	return (*this);
}

