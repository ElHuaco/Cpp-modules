/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:12:09 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/01 16:22:06 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include <string>
# include <iostream>

class	ScravTrap
{
	public:
		ScravTrap(void);
		ScravTrap(std::string name);
		ScravTrap(ScravTrap const &rhs);
		~ScravTrap(void);

		ScravTrap	&operator=(ScravTrap const &rhs);

		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const &target);

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
		void			setName(std::string name);
		void			setInitialValues(void);

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
		static std::string	_funny_challenges[5];
};
#endif
