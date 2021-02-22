/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:27:01 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 12:15:56 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string zombie_event::_nameList[] = {"Mr. Skeltal", "Tiny Bones", "Pinhead",
	"Johny Pepperoni", "Lord Varrgaroth, Sire of the Bloodskies"};

zombie_event::zombie_event(void)
{
	return;
}

zombie_event::~zombie_event(void)
{
	return;
}

void		zombie_event::setZombieType(zombie *dead, std::string type)
{
	dead->set_type(type);
	return;
}

zombie		*zombie_event::newZombie(std::string name)
{
	zombie	*dead = new zombie(name);
	return (dead);
}

void		zombie_event::randomChump(void)
{
	int		random_number = std::rand() % 5;
	zombie	random_zombie(_nameList[random_number]);
	random_zombie.announce();
	return;
}
