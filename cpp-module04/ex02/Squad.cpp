/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 07:31:37 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 11:06:42 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void) : _numUnits(0), _unitArray(0)
{
	return;
}

Squad::Squad(Squad const &rhs)
{
	*this = rhs;
	return;
}

Squad::~Squad(void)
{
	int		i;
	int		total;

	total = this->_numUnits;
	i = -1;
	while (++i < total)
			delete this->_unitArray[i];
	delete[] this->_unitArray;
	return;
}

Squad			&Squad::operator=(Squad const &rhs)
{
	int		totalUnits;
	int		i;

	if (this == &rhs)
		return (*this);
	if ((totalUnits = this->_numUnits) != 0)
	{
		i = -1;
		while (++i < totalUnits)
			delete this->_unitArray[i];
		delete[] this->_unitArray;
	}
	totalUnits = rhs._numUnits;
	this->_unitArray = new ISpaceMarine*[totalUnits];
	i = -1;
	while (++i < totalUnits)
		this->_unitArray[i] = rhs._unitArray[i]->clone();
	this->_numUnits = totalUnits;
	return (*this);
}

int				Squad::getCount(void) const
{
	return (this->_numUnits);
}

ISpaceMarine	*Squad::getUnit(int n) const
{
	if ((n < 0) || (n >= this->_numUnits))
		return (0);
	return (this->_unitArray[n]);
}

int				Squad::push(ISpaceMarine *recruit)
{
	int		i;
	int		total;

	if (!(recruit))
		return (this->_numUnits);
	total = this->_numUnits;
	i = -1;
	while (++i < total)
		if (recruit == this->_unitArray[i])
			return (total);
	ISpaceMarine **temp = new ISpaceMarine*[total + 1];
	i = -1;
	while (++i < total)
		temp[i] = this->_unitArray[i];
	temp[i] = recruit;
	delete[] this->_unitArray;
	this->_unitArray = temp;
	this->_numUnits = total + 1;
	return (total + 1);
}
