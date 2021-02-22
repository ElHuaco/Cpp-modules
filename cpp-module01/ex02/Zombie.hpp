/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:12:11 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/22 13:12:47 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	zombie
{
	public:
		zombie(void);
		zombie(std::string name);
		~zombie(void);
		void		announce(void) const;
		void		set_type(std::string type);
		void		set_name(std::string name);
		std::string	get_name(void) const;
	private:
		std::string	_name;
		std::string	_type;
};
#endif
