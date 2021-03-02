/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:32 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 12:14:17 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

void		NinjaTrap::setInitialValues(void)
{
	this->setHP(60);
	this->setMaxHP(60);
	this->setEP(120);
	this->setMaxEP(120);
	this->setLevel(1);
	this->setMeleeDMG(60);
	this->setRangedDMG(5);
	this->setArmor(0);
	return;
}

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	std::cout << "Default N1NJ-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	std::cout << "String N1NJ-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &rhs)
{
	std::cout << "Copy N1NJ-TP constructor called" << std::endl;
	*this = rhs;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "N1NJ-TP Destructor called" << std::endl;
	return;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &rhs)
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

void		NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout << "Gasp! It's a Ninja Duel! " << std::endl;
	std::cout << this->getName() << " attacks... But " << target.getName() << " too!";
	std::cout << std::endl;
	this->takeDamage(target.getMeleeDMG());
	target.takeDamage(this->getMeleeDMG());
	return;
}

void		NinjaTrap::ninjaShoebox(ScravTrap &target)
{
	std::cout << "N1NJ-TP " << this->getName() << ": \"Nothing personal, ";
	std::cout << target.getName() << ".\"" << std::endl;
	target.takeDamage(this->getMeleeDMG());
	return;
}

void		NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout << "N1NJ-TP " << this->getName() << ": \"Finally, a worthy opponent!\"";
	std::cout << std::endl;
	std::cout << "FR4G-TP " << target.getName() << ": \"Good, twice the pride, double the fall\"";
	std::cout << std::endl;
	this->takeDamage(target.getMeleeDMG());
	target.takeDamage(this->getMeleeDMG());
	return;
}

void		NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	std::cout << "N1NJ-TP " << this->getName() << ": \"I diagnose you with death, ";
	std::cout << target.getName() << "!" << std::endl;
	target.takeDamage(this->getMeleeDMG());
	return;
}
