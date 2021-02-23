/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:44:48 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 10:39:55 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class	Human
{
	public:
		Human(void);
		~Human(void);

		Brain const		&getBrain(void) const;
		unsigned long	*identify(void) const;
		int				get_age(void) const;
		void			set_age(int age);
	private:
		Brain const		_brain;
		int				_age;
};
#endif
