/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:01:08 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 16:08:26 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	return;
}

Ice::~Ice(void) : ~AMateria()
{
	return;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	return;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_xp = rhs._xp;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	Ice		*shard = new Ice;
	*shard = *this;
	return (shard);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}
