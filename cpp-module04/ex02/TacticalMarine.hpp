/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:19:16 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 08:28:51 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"
# include <string>
# include <iostream>

class	TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const &other);
		virtual		~TacticalMarine(void);

		TacticalMarine	&operator=(TacticalMarine const &rhs);

		virtual ISpaceMarine	*clone(void) const;
		virtual void			battleCry(void) const;
		virtual void			rangedAttack(void) const;
		virtual void			meleeAttack(void) const;
	private:
		int	_faith;
};
#endif
