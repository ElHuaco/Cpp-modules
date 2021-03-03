/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:03:34 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 10:24:25 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(void);
		Peon(std::string name);
		Peon(Peon const &rhs);
		virtual		~Peon(void);

		Peon		&operator=(Peon const &rhs);

		virtual void getPolymorphed(void) const;
};
#endif
