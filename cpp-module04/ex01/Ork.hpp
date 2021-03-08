/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ork.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:31:50 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:32:21 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORK_HPP
# define ORK_HPP

# include "Enemy.hpp"

class	Ork : public Enemy
{
	public:
		Ork(void);
		Ork(Ork const &rhs);
		virtual		~Ork(void);
		Ork	&operator=(Ork const &rhs);
};
#endif

