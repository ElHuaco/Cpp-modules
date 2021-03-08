/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:52:06 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 08:21:22 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	return;
}

Character::Character(std::string const &name) : _name(name)
{
	int		i;

	this->_inventory = new AMateria *[INVENTORY_SIZE];
	i = -1;
	while (++i < INVENTORY_SIZE)
		this->_inventory[i] = 0;
	return;
}

Character::Character(Character const &other)
{
	*this = other;
	return;
}

Character::~Character(void)
{
	int		i;

	while (++i < INVENTORY_SIZE)
		delete this->_inventory[i];
	delete[] this->_inventory;
	return;
}

Character		&Character::operator=(Character const &rhs)
{
	int		i;
	if (this == &rhs)
		return (*this);
	i = -1;
	while (++i < INVENTORY_SIZE)
		delete this->_inventory[i];
	delete[] this->_inventory;
	this->_inventory = new AMateria*[INVENTORY_SIZE];
	if (rhs._inventory == 0)
		return (*this);
	i = -1;
	while (++i < INVENTORY_SIZE)
	{
		if (rhs._inventory[i] != 0)	
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

AMateria			*Character::getMateria(int index) const
{
	if ((index < 0) || (index >= INVENTORY_SIZE))
		return (0);
	return (this->_inventory[index]);
}
void			Character::equip(AMateria *m)
{
	int		i;
	int		count;

	if (!m)
		return;
	count = 0;
	i = -1;
	while (++i < INVENTORY_SIZE)
	{
		if (m == this->_inventory[i])
			return;
		if (this->_inventory[i] != 0)
			count++;
	}
	if (count == INVENTORY_SIZE)
		return;
	AMateria **temp = new AMateria*[INVENTORY_SIZE];
	i = -1;
	while (++i < INVENTORY_SIZE)
		temp[i] = 0;
	i = -1;
	while (++i < INVENTORY_SIZE)
		if (this->_inventory[i] != 0)
			temp[i] = this->_inventory[i];
	i = -1;
	while (++i < INVENTORY_SIZE)
	{
		if (this->_inventory[i] == 0)
		{
			temp[i] = m;
			break;
		}
	}
	delete[] this->_inventory;
	this->_inventory = temp;
	return;
}

void			Character::unequip(int index)
{
	if ((index < 0) || (index >= INVENTORY_SIZE))
		return;
	if (this->_inventory[index] != 0)
		this->_inventory[index] = 0;
	return;
}

void			Character::use(int index, ICharacter &target)
{
	if ((index < 0) || (index >= INVENTORY_SIZE))
		return;
	if (this->_inventory[index] != 0)
		this->_inventory[index]->use(target);
	return;
}
