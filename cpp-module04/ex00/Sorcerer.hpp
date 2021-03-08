/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:27 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:24:26 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class	Sorcerer
{
	public:
		Sorcerer(Sorcerer const &rhs);
		Sorcerer(std::string name, std::string title);
		~Sorcerer(void);

		Sorcerer	&operator=(Sorcerer const &rhs);

		std::string	getName(void) const;
		std::string	getTitle(void) const;

		void		setName(std::string name);
		void		setTitle(std::string title);

		void		polymorph(Victim const &target) const;

	private:
		Sorcerer(void);
		std::string	_name;
		std::string	_title;
};

std::ostream		&operator<<(std::ostream &os, Sorcerer const &rhs);
#endif
