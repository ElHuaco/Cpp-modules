/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:26 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/01 17:07:51 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

void		ScravTrap::setInitialValues(void)
{
	this->_HP = 100;
	this->_maxHP = 100;
	this->_EP = 50;
	this->_maxEP = 50;
	this->_level = 1;
	this->_meleeDMG = 20;
	this->_rangedDMG = 15;
	this->_armor = 3;
	return;
}

ScravTrap::ScravTrap(void) : _name("Sample")
{
	std::cout << "Default SCRV-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

ScravTrap::ScravTrap(std::string name) : _name(name)
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

unsigned int	ScravTrap::getHP(void) const
{
	return (this->_HP);
}

unsigned int	ScravTrap::getMaxHP(void) const
{
	return (this->_maxHP);
}

unsigned int	ScravTrap::getEP(void) const
{
	return (this->_EP);
}

unsigned int	ScravTrap::getMaxEP(void) const
{
	return (this->_maxEP);
}

unsigned int	ScravTrap::getLevel(void) const
{
	return (this->_level);
}

unsigned int	ScravTrap::getMeleeDMG(void) const
{
	return (this->_meleeDMG);
}

unsigned int	ScravTrap::getRangedDMG(void) const
{
	return (this->_rangedDMG);
}

unsigned int	ScravTrap::getArmor(void) const
{
	return (this->_armor);
}

std::string		ScravTrap::getName(void) const
{
	return (this->_name);
}

void			ScravTrap::setHP(unsigned int amount)
{
	this->_HP = amount;
	return;
}

void			ScravTrap::setEP(unsigned int amount)
{
	this->_EP = amount;
	return;
}

void			ScravTrap::setLevel(unsigned int amount)
{
	this->_level = amount;
	return;
}

void			ScravTrap::setArmor(unsigned int amount)
{
	this->_armor = amount;
	return;
}

void			ScravTrap::setMeleeDMG(unsigned int amount)
{
	this->_meleeDMG = amount;
	return;
}

void			ScravTrap::setRangedDMG(unsigned int amount)
{
	this->_rangedDMG = amount;
	return;
}

void			ScravTrap::setName(std::string name)
{
	this->_name = name;
	return;
}

std::string ScravTrap::_funny_challenges[] = {"to a game of La Oca!",
	"to a FREESTYLE OUIJA RAP!", "not to breath!",
	"to defy the Elder King, Melkor, Creator of Arda!",
	"to name a good Star Wars film!"};

void			ScravTrap::challengeNewcomer(std::string const &target)
{
	int		random_number;

	if (this->_EP < 25)
	{
		std::cout << "SCRV-TP " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	else
	{
		random_number = rand() % 5;
		this->_EP -= 25;
		std::cout << "SCRV-TP " << this->_name << " challenges " << target << " ";
		std::cout << ScravTrap::_funny_challenges[random_number];
		std::cout << std::endl;
		return;
	}
}

void			ScravTrap::meleeAttack(std::string const &target)
{
	std::cout << "SCRV-TP " << this->_name << " attacks " << target;
	std::cout << " at melee, causing " << this->_meleeDMG << " points of damage!";
	std::cout << std::endl;
	return;
}

void			ScravTrap::rangedAttack(std::string const &target)
{
	std::cout << "SCRV-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDMG << " points of damage!";
	std::cout << std::endl;
	return;
}

void			ScravTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_HP + this->_armor)
		this->_HP = 0;
	else
		this->_HP -= amount - this->_armor;
	std::cout << "Ouch! " << this->_name << "'s HP: " << this->_HP << std::endl;
	return;
}

void			ScravTrap::beRepaired(unsigned int amount)
{
	if (amount >= this->_maxHP - this->_HP)
		this->_HP = this->_maxHP;
	else
		this->_HP += amount;
	std::cout << "Thanks Mr. Roboto! " << this->_name << "'s HP: " << this->_HP << std::endl;
	return;
}
