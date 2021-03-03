/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:19:57 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:52:54 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	AWeapon
{
	public:
		AWeapon(std::string const &name, int apcostm, int damage);
		virtual	~AWeapon(void);

		std::string const	&getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;

		void				setName(std::string const &name);
		void				setAPCost(int apcost);
		void				setDamage(int damage);

		virtual void		attack(void) const = 0;

	private:
		AWeapon(void);
		std::string			_name;
		int					_apcost;
		int					_damage;
};
#endif
