/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:47:42 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:50:32 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class	SuperMutant : public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const &rhs);
		virtual		~SuperMutant(void);
		SuperMutant	&operator=(SuperMutant const &rhs);

		virtual void	takeDamage(int amount);
};
#endif
