/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:25:54 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 09:46:12 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void		FragTrap::setInitialValues(void)
{
	this->setHP(100);
	this->setMaxHP(100);
	this->setEP(100);
	this->setMaxEP(100);
	this->setLevel(1);
	this->setMeleeDMG(30);
	this->setRangedDMG(20);
	this->setArmor(5);
	return;
}

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Default FR4G-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "String FR4G-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

FragTrap::FragTrap(FragTrap const &rhs)
{
	std::cout << "Copy FR4G-TP constructor called" << std::endl;
	*this = rhs;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP Destructor called" << std::endl;
//	this->ClapTrap::~ClapTrap(); //Needed?
	return;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
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
std::string FragTrap::_funny_attacks[] = {" shoots an arrow to the knee of ",
" throws Narsil, Sword of Isildur, Son of Elendil, Son of Amandil, Lord of Andúnië at ",
" throws an eBic burn to ", " laughs at ", " whips some jumper cables at "};

void			FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int		random_number;

	if (this->getEP() < 25)
	{
		std::cout << "FR4G-TP " << this->getName() << " is out of energy!" << std::endl;
		return;
	}
	else
	{
		random_number = rand() % 5;
		this->setEP(this->getEP() - 25);
		std::cout << "FR4G-TP " << this->getName();
		std::cout << FragTrap::_funny_attacks[random_number] << target;
		std::cout << " causing, " << this->getRangedDMG() << " points of damage!";
		std::cout << std::endl;
		return;
	}
}
