/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:17:51 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/02/23 10:42:39 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	public:
		Brain(void);
		~Brain(void);

		void			set_volume(int volume);
		int				get_volume(void) const;
		unsigned long	*identify(void) const;
	private:
		int	_volume;
};
#endif
