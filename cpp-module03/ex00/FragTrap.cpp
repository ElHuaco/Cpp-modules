/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:25:54 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/01 13:20:20 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _name(nullptr)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : _name(name)
{
	std::cout << "String constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
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

std::string _funny_attacks[] = {" shoots an arrow to the knee of ",
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
	return;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if (amount >= this->_maxHP - this->_HP)
		this->_HP = this->_maxHP;
	else
		this->_HP += amount;
	return;
}
