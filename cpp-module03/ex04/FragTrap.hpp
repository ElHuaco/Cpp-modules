/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:02:34 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 11:58:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &rhs);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &rhs);

		void		vaulthunter_dot_exe(std::string const &target);
		void		setInitialValues(void);

	private:
		static std::string	_funny_attacks[5];
};
#endif
