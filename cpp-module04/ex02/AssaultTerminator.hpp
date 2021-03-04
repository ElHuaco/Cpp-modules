/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:37:05 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 08:38:02 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <string>
# include <iostream>

class	AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const &other);
		virtual		~AssaultTerminator(void);

		AssaultTerminator	&operator=(AssaultTerminator const &rhs);

		virtual ISpaceMarine	*clone(void) const;
		virtual void			battleCry(void) const;
		virtual void			rangedAttack(void) const;
		virtual void			meleeAttack(void) const;
	private:
		int	_faith;
};
#endif
