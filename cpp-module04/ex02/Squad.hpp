/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 07:23:02 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 09:13:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
	public:
		Squad(void);
		Squad(Squad const &rhs);
		virtual		~Squad(void);

		Squad		&operator=(Squad const &rhs);

		virtual int				getCount(void) const;
		virtual ISpaceMarine*	getUnit(int n) const;
		virtual int				push(ISpaceMarine *unit);

	private:
		int				_numUnits;
		ISpaceMarine	**_unitArray;
};
#endif
