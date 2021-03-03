/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:20:08 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 13:02:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(void)
{
	return;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
	_name(name), _apcost(apcost), _damage(damage)
{
	return;
}

AWeapon::~AWeapon(void)
{
	return;
}

std::string const	&AWeapon::getName(void) const
{
	return (this->_name);
}

int					AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

int					AWeapon::getDamage(void) const
{
	return (this->_damage);
}

void				AWeapon::setName(std::string const &name)
{
	this->_name = name;
	return;
}

void				AWeapon::setAPCost(int apcost)
{
	this->_apcost = apcost;
	return;
}

void				AWeapon::setDamage(int damage)
{
	this->_damage = damage;
	return;
}
