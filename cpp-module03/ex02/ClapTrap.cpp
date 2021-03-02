/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:08:14 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 12:02:13 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Sample")
{
	std::cout << "Default CL4P-TP constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "String CL4P-TP constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &rhs)
{
	std::cout << "Copy CL4P-TP constructor called" << std::endl;
	*this = rhs;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP Destructor called" << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_HP = rhs._HP;
	this->_maxHP = rhs._maxHP;
	this->_EP = rhs._EP;
	this->_maxEP = rhs._maxEP;
	this->_level = rhs._level;
	this->_meleeDMG = rhs._meleeDMG;
	this->_rangedDMG = rhs._rangedDMG;
	this->_armor = rhs._armor;
	return (*this);
}

unsigned int	ClapTrap::getHP(void) const
{
	return (this->_HP);
}

unsigned int	ClapTrap::getMaxHP(void) const
{
	return (this->_maxHP);
}

unsigned int	ClapTrap::getEP(void) const
{
	return (this->_EP);
}

unsigned int	ClapTrap::getMaxEP(void) const
{
	return (this->_maxEP);
}

unsigned int	ClapTrap::getLevel(void) const
{
	return (this->_level);
}

unsigned int	ClapTrap::getMeleeDMG(void) const
{
	return (this->_meleeDMG);
}

unsigned int	ClapTrap::getRangedDMG(void) const
{
	return (this->_rangedDMG);
}

unsigned int	ClapTrap::getArmor(void) const
{
	return (this->_armor);
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

void			ClapTrap::setHP(unsigned int amount)
{
	this->_HP = amount;
	return;
}

void			ClapTrap::setMaxHP(unsigned int amount)
{
	this->_maxHP = amount;
	return;
}

void			ClapTrap::setEP(unsigned int amount)
{
	this->_EP = amount;
	return;
}

void			ClapTrap::setMaxEP(unsigned int amount)
{
	this->_maxEP = amount;
	return;
}

void			ClapTrap::setLevel(unsigned int amount)
{
	this->_level = amount;
	return;
}

void			ClapTrap::setArmor(unsigned int amount)
{
	this->_armor = amount;
	return;
}

void			ClapTrap::setMeleeDMG(unsigned int amount)
{
	this->_meleeDMG = amount;
	return;
}

void			ClapTrap::setRangedDMG(unsigned int amount)
{
	this->_rangedDMG = amount;
	return;
}

void			ClapTrap::setName(std::string name)
{
	this->_name = name;
	return;
}

void			ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "CL4P-TP " << this->_name << " attacks " << target;
	std::cout << " at melee, causing " << this->_meleeDMG << " points of damage!";
	std::cout << std::endl;
	return;
}

void			ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "CL4P-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDMG << " points of damage!";
	std::cout << std::endl;
	return;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_HP + this->_armor)
		this->_HP = 0;
	else
		this->_HP -= amount - this->_armor;
	std::cout << "Ouch! " << this->_name << "'s HP: " << this->_HP << std::endl;
	return;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (amount >= this->_maxHP - this->_HP)
		this->_HP = this->_maxHP;
	else
		this->_HP += amount;
	std::cout << "Thanks Mr. Roboto! " << this->_name << "'s HP: " << this->_HP << std::endl;
	return;
}
