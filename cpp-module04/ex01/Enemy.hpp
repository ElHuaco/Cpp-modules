/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:38:18 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:47:37 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class	Enemy
{
	public:
		Enemy(int hp, std::string const &type);
		virtual		~Enemy(void);
		Enemy(Enemy const &rhs);
		Enemy		&operator=(Enemy const &rhs);

		std::string const	&getType(void) const;
		int					getHP(void) const;

		void				setType(std::string const &type);
		void				setHP(int hp);

		virtual void		takeDamage(int amount);

	private:
		Enemy(void);
		std::string			_type;
		int					_HP;
};
#endif
