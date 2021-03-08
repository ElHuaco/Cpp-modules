/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ork.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:13:58 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:14:19 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORK_HPP
# define ORK_HPP

# include "Victim.hpp"

class Ork : public Victim
{
	public:
		Ork(void);
		Ork(std::string name);
		Ork(Ork const &rhs);
		virtual		~Ork(void);

		Ork		&operator=(Ork const &rhs);

		virtual void getPolymorphed(void) const;
};
#endif
