/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:17:36 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 12:13:28 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <cstdlib>
#include <string>
#include <ctime>

class	zombie_event
{
	public:
		zombie_event();
		~zombie_event();
		static void		setZombieType(zombie *deadthing, std::string type);
		static zombie	*newZombie(std::string name);
		static void		randomChump(void);
	private:
		static std::string		_nameList[5];
};
#endif
