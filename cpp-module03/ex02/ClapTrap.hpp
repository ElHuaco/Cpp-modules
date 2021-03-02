/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:04:00 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 09:43:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class		ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &rhs);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &rhs);

		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

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
		void			setMaxHP(unsigned int amount);
		void			setEP(unsigned int amount);
		void			setMaxEP(unsigned int amount);
		void			setLevel(unsigned int amount);
		void			setArmor(unsigned int amount);
		void			setMeleeDMG(unsigned int amount);
		void			setRangedDMG(unsigned int amount);
		void			setName(std::string name);

	private:
		unsigned int	_HP;
		unsigned int	_maxHP;
		unsigned int	_EP;
		unsigned int	_maxEP;
		unsigned int	_level;
		std::string		_name;
		unsigned int	_meleeDMG;
		unsigned int	_rangedDMG;
		unsigned int	_armor;
};
#endif
