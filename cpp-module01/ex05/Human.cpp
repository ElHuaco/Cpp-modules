/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:47:35 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 10:39:32 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	return;
}

Human::~Human(void)
{
	return;
}

void	Human::set_age(int age)
{
	this->_age = age;
	return;
}

int		Human::get_age(void) const
{
	return (this->_age);
}

Brain const		&Human::getBrain(void) const
{
	return (this->_brain);
}

unsigned long	*Human::identify(void) const
{
	return (this->getBrain().identify());
}
