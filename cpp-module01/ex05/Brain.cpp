/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:21:12 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 10:43:14 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	return;
}

Brain::~Brain(void)
{
	return;
}

void	Brain::set_volume(int volume)
{
	this->_volume = volume;
	return;
}

int		Brain::get_volume(void) const
{
	return (this->_volume);
}

unsigned long	*Brain::identify(void) const
{
	return ((unsigned long *)this);
}
