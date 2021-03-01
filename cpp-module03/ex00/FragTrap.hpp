/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:02:34 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/01 12:57:05 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>

class FragTrap
{
	public:
		FragTrap(void);
		FrapTrap(std::string name);
		FragTrap(FragTrap const &rhs);
		~FragTrap(void);

		FrapTrap	&operator=(FragTrap const &rhs);

		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const &target);

		unsigned int	getHP(void) const;
		unsigned int	getMaxHP(void) const;
		unsigned int	getEP(void) const;
		unsigned int	getMaxEP(void) const;
		unsigned int	getLevel(void) const;
		unsigned int	getMeleeDMG(void) const;
		unsigned int	getRangedDMG(void) const;
		unsigned int	getArmor(void) const;
		std::string		getName(void) const;
		
		void			setHP(unsigned int amount);
		void			setEP(unsigned int amount);
		void			setLevel(unsigned int amount);
		void			setArmor(unsigned int amount);
		void			setMeleeDMG(unsigned int amount);
		void			setRangedDMG(unsigned int amount);

	private:
		unsigned int	_HP = 100;
		unsigned int	_maxHP = 100;
		unsigned int	_EP = 100;
		unsigned int	_maxEP = 100;
		unsigned int	_level = 1;
		std::string		_name;
		unsigned int	_meleeDMG = 30;
		unsigned int	_rangedDMG = 20;
		unsigned int	_armor = 5;
		static std::string	_funny_attacks[5];
};
#endif
