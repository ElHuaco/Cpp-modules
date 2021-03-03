/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:41:59 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 13:00:44 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void)
{
	return;
}

Enemy::Enemy(int hp, std::string const &type) : _HP(hp), _type(type)
{
	return;
}

Enemy::Enemy(Enemy const &rhs)
{
	*this = rhs;
	return;
}

Enemy::~Enemy(void)
{
	return;
}

void		Enemy::setType(std::string const &type)
{
	this->_type = type;
	return;
}

void		Enemy::setHP(int hp)
{
	this->_HP = hp;
	return;
}

std::string const	&Enemy::getType(void) const
{
	return (this->_type);
}

int					Enemy::getHP(void) const
{
	return (this->_HP);
}

Enemy		&Enemy::operator=(Enemy const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	this->_HP = rhs._HP;
	return (*this);
}

void		Enemy::takeDamage(int amount)
{
	if (amount <= 0)
		return;
	if (this->_HP <= amount)
		this->_HP = 0;
	else
		this->_HP -= amount;
	return;
}
