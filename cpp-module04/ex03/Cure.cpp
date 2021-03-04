/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:07:04 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 16:08:14 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	return;
}

Cure::~Cure(void) : ~AMateria()
{
	return;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	return;
}

Cure			&Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_xp = rhs._xp;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	Cure	*heal = new Cure;
	*heal = *this;
	return (heal);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}
