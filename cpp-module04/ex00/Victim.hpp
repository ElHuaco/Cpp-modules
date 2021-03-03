/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:43:20 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 10:24:03 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class	Victim
{
	public:
		Victim(void);
		Victim(std::string name);
		Victim(Victim const &rhs);
		virtual			~Victim(void);

		Victim			&operator=(Victim const &rhs);

		std::string		getName(void) const;
		void			setName(std::string name);
	
		virtual void	getPolymorphed(void) const;

	private:
		std::string		_name;
};

std::ostream		&operator<<(std::ostream &os, Victim const &rhs);

#endif
