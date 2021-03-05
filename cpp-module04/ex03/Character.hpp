/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:13:04 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/05 12:48:02 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# define INVENTORY_SIZE 4

class	Character : public ICharacter
{
	public:
		Character(std::string const &name);
		Character(Character const &other);
		virtual ~Character(void);

		Character		&operator=(Character const &rhs);

		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int dx);
		virtual void				use(int idx, ICharacter &target);
	
		AMateria		*getMateria(int idx) const;

	private:
		Character(void);
		std::string			_name;
		AMateria			**_inventory;
};
#endif
