/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:44:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 13:13:25 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"
# include <string>
# include <cstdlib>
# include <ctime>

class		ZombieHorde
{
	public:
		ZombieHorde(int N);
		~ZombieHorde(void);
		zombie		*get_first_zombie(void) const;
	private:
		static std::string	_nameList[10];
		zombie		*_first_zombie;
};
#endif
