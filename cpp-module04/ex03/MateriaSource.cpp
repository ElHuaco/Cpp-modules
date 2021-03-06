/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:52:46 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 08:49:01 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	int		i;

	this->_sources = new AMateria*[SOURCE_MAX];
	i = -1;
	while (++i < SOURCE_MAX)
		this->_sources[i] = 0;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	int		i;

	this->_sources = new AMateria*[SOURCE_MAX];
	i = -1;
	while (++i < SOURCE_MAX)
		this->_sources[i] = 0;
	*this = other;
	return;
}

MateriaSource::~MateriaSource(void)
{
	int		i;
	
	i = -1;
	while (++i < SOURCE_MAX)
		delete this->_sources[i];
	delete[] this->_sources;
}

MateriaSource		&MateriaSource::operator=(MateriaSource const &rhs)
{
	int		i;

	if (this == &rhs)
		return (*this);
	i = -1;
	while (++i < SOURCE_MAX)
		delete this->_sources[i];
	delete[] this->_sources;
	this->_sources = new AMateria*[SOURCE_MAX];
	if (rhs._sources == 0)
		return (*this);
	i = -1;
	while (++i < SOURCE_MAX)
		if (rhs._sources[i] != 0)
			this->_sources[i] = rhs._sources[i]->clone();
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	int		i;
	int		count;

	if (!m)
		return;
	count = 0;
	i = -1;
	while (++i < SOURCE_MAX)
	{
		if (m == this->_sources[i])
			return;
		if (this->_sources[i] != 0)
			count++;
	}
	if (count == SOURCE_MAX)
		return;
	AMateria **temp = new AMateria*[SOURCE_MAX];
	i = -1;
	while (++i < SOURCE_MAX)
		temp[i] = 0;
	i = -1;
	while (++i < SOURCE_MAX)
		if (this->_sources[i] != 0)
			temp[i] = this->_sources[i];
	i = -1;
	while (++i < SOURCE_MAX)
	{
		 if (this->_sources[i] == 0)
		 {
			 temp[i] = m;
			 break;
		 }
	}
	delete[] this->_sources;
	this->_sources = temp;
	return;
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	int		i;

	i = -1;
	while (++i < SOURCE_MAX)
		if (this->_sources[i]->getType() == type)
			return (this->_sources[i]->clone()); 
	return (0);
}
