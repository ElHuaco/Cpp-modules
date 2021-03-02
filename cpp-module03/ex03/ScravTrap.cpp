/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:26 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 10:02:34 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

void		ScravTrap::setInitialValues(void)
{
	this->setHP(100);
	this->setMaxHP(100);
	this->setEP(50);
	this->setMaxEP(50);
	this->setLevel(1);
	this->setMeleeDMG(20);
	this->setRangedDMG(15);
	this->setArmor(3);
	return;
}

ScravTrap::ScravTrap(void) : ClapTrap()
{
	std::cout << "Default SCRV-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

ScravTrap::ScravTrap(std::string name) : ClapTrap(name)
{
	std::cout << "String SCRV-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

ScravTrap::ScravTrap(ScravTrap const &rhs)
{
	std::cout << "Copy SCRV-TP constructor called" << std::endl;
	*this = rhs;
	return;
}

ScravTrap::~ScravTrap(void)
{
	std::cout << "SCRV-TP Destructor called" << std::endl;
	return;
}

ScravTrap	&ScravTrap::operator=(ScravTrap const &rhs)
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

std::string ScravTrap::_funny_challenges[] = {"to a game of La Oca!",
	"to a FREESTYLE OUIJA RAP!", "not to breath!",
	"to defy the Elder King, Melkor, Creator of Arda!",
	"to name a good Star Wars film!"};

void			ScravTrap::challengeNewcomer(std::string const &target)
{
	int		random_number;

	if (this->getEP() < 25)
	{
		std::cout << "SCRV-TP " << this->getName() << " is out of energy!" << std::endl;
		return;
	}
	else
	{
		random_number = rand() % 5;
		this->setEP(this->getEP() - 25);
		std::cout << "SCRV-TP " << this->getName() << " challenges " << target << " ";
		std::cout << ScravTrap::_funny_challenges[random_number];
		std::cout << std::endl;
		return;
	}
}
