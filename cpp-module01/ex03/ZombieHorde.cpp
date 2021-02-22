/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:41:24 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 13:21:15 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

std::string ZombieHorde::_nameList[] = {"Maggothead", "Eye sockets", "Bilis",
	"Hurty", "Twisted Ankle",  "AnkleTwister", "Fat", "Bloated", "No feet",
	"Slurpy"};

ZombieHorde::ZombieHorde(int N)
{
	int		i;
	int		random_number;

	if (N <= 0)
		return;
	zombie	*Horde = new zombie[N];
	i = -1;
	while (++i < N)
	{
		random_number = std::rand() % 10;
		Horde[i].set_name(ZombieHorde::_nameList[random_number]);
		Horde[i].announce();
	}
	this->_first_zombie = Horde;
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete []this;
	return;
}

zombie	*ZombieHorde::get_first_zombie(void) const
{
	return (this->_first_zombie);
}
