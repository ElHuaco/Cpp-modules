/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:09:53 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 13:04:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	return;
}

Character::Character(std::string const &name) : _name(name), _AP(40),
	_equippedWeapon(nullptr)
{
	return;
}

Character::Character(Character const &rhs)
{
	*this = rhs;
	return;
}

Character::~Character(void)
{
	return;
}

Character		&Character::operator=(Character const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_AP = rhs._AP;
	this->_equippedWeapon = rhs._equippedWeapon;
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

AWeapon				*Character::getWeapon(void) const
{
	return (this->_equippedWeapon);
}

int					Character::getAP(void) const
{
	return (this->_AP);
}

void				Character::recoverAP(void)
{
	this->_AP += 10;
	if (this->_AP > 40)
		this->_AP = 40;
	return;
}

void				Character::equip(AWeapon *weapon)
{
	this->_equippedWeapon = weapon;
	return;
}

void				Character::attack(Enemy *target)
{
	if (this->_equippedWeapon == nullptr)
	{
		std::cout << this->_name << " doesn't have a weapon equipped!" << std::endl;
		return;
	}
	if (this->_equippedWeapon->getAPCost() > this->_AP)
	{
		std::cout << this->_name << " is out of AP!" << std::endl;
		return;
	}
	if (target == nullptr)
	{
		std::cout << "The target is dead or doesn't exist!" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks " << target->getType() << " with a ";
	std::cout << this->_equippedWeapon->getName() << std::endl;
	this->_equippedWeapon->attack();
	target->takeDamage(this->_equippedWeapon->getDamage());
	if (target->getHP() == 0)
		delete target;
	this->_AP -= this->_equippedWeapon->getAPCost();
	return;
}

std::ostream		&operator<<(std::ostream &os, Character const &rhs)
{
	os << rhs.getName() << " has " << rhs.getAP() << " AP and";
	if (rhs.getWeapon() == nullptr)
		os << " is unarmed";
	else
		os << " wields a " << rhs.getWeapon()->getName();
	return (os);
}
