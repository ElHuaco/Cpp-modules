/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:25:54 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/01 15:55:51 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void		FragTrap::setInitialValues(void)
{
	this->_HP = 100;
	this->_maxHP = 100;
	this->_EP = 100;
	this->_maxEP = 100;
	this->_level = 1;
	this->_meleeDMG = 30;
	this->_rangedDMG = 20;
	this->_armor = 5;
	return;
}

FragTrap::FragTrap(void) : _name("Sample")
{
	std::cout << "Default FR4G-TP constructor called" << std::endl;
	this->setInitialValues();
	return;
}

FragTrap::FragTrap(std::string name) : _name(name)
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
	return;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
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

unsigned int	FragTrap::getHP(void) const
{
	return (this->_HP);
}

unsigned int	FragTrap::getMaxHP(void) const
{
	return (this->_maxHP);
}

unsigned int	FragTrap::getEP(void) const
{
	return (this->_EP);
}

unsigned int	FragTrap::getMaxEP(void) const
{
	return (this->_maxEP);
}

unsigned int	FragTrap::getLevel(void) const
{
	return (this->_level);
}

unsigned int	FragTrap::getMeleeDMG(void) const
{
	return (this->_meleeDMG);
}

unsigned int	FragTrap::getRangedDMG(void) const
{
	return (this->_rangedDMG);
}

unsigned int	FragTrap::getArmor(void) const
{
	return (this->_armor);
}

std::string		FragTrap::getName(void) const
{
	return (this->_name);
}

void			FragTrap::setHP(unsigned int amount)
{
	this->_HP = amount;
	return;
}

void			FragTrap::setEP(unsigned int amount)
{
	this->_EP = amount;
	return;
}

void			FragTrap::setLevel(unsigned int amount)
{
	this->_level = amount;
	return;
}

void			FragTrap::setArmor(unsigned int amount)
{
	this->_armor = amount;
	return;
}

void			FragTrap::setMeleeDMG(unsigned int amount)
{
	this->_meleeDMG = amount;
	return;
}

void			FragTrap::setRangedDMG(unsigned int amount)
{
	this->_rangedDMG = amount;
	return;
}

void			FragTrap::setName(std::string name)
{
	this->_name = name;
	return;
}

std::string FragTrap::_funny_attacks[] = {" shoots an arrow to the knee of ",
" throws Narsil, Sword of Isildur, Son of Elendil, Son of Amandil, Lord of Andúnië at ",
" throws an eBic burn to ", " laughs at ", " whips some jumper cables at "};

void			FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int		random_number;

	if (this->_EP < 25)
	{
		std::cout << "FR4G-TP " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	else
	{
		random_number = rand() % 5;
		this->_EP -= 25;
		std::cout << "FR4G-TP " << this->_name;
		std::cout << FragTrap::_funny_attacks[random_number] << target;
		std::cout << " causing, " << this->_rangedDMG << " points of damage!";
		std::cout << std::endl;
		return;
	}
}

void			FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " at melee, causing " << this->_meleeDMG << " points of damage!";
	std::cout << std::endl;
	return;
}

void			FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDMG << " points of damage!";
	std::cout << std::endl;
	return;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_HP + this->_armor)
		this->_HP = 0;
	else
		this->_HP -= amount - this->_armor;
	std::cout << "Ouch! " << this->_name << "'s HP: " << this->_HP << std::endl;
	return;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if (amount >= this->_maxHP - this->_HP)
		this->_HP = this->_maxHP;
	else
		this->_HP += amount;
	std::cout << "Thanks Mr. Roboto! " << this->_name << "'s HP: " << this->_HP << std::endl;
	return;
}
