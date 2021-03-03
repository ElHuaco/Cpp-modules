/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:04:47 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:54:54 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class	Character
{
	public:
		Character(std::string const &name);
		Character(Character const &rhs);
		~Character(void);
		Character		&operator=(Character const &rhs);

		void			recoverAP(void);
		void			equip(AWeapon *weapon);
		void			attack(Enemy *target);

		std::string const	&getName(void) const;
		AWeapon				*getWeapon(void) const;
		int					getAP(void) const;

	private:
		Character(void);
		std::string			_name;
		int					_AP;
		AWeapon				*_equippedWeapon;
};

std::ostream	&operator<<(std::ostream &os, Character const &rhs);
#endif
