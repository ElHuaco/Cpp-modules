/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:55:53 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 12:52:35 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class	RadScorpion : public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const &rhs);
		virtual		~RadScorpion(void);
		RadScorpion	&operator=(RadScorpion const &rhs);
};
#endif
