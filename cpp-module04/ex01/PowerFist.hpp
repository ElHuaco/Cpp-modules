/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:37:13 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 11:37:38 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class	PowerFist : public AWeapon
{
	public:
		PowerFist(void);
		PowerFist(PowerFist const &rhs);
		virtual			~PowerFist(void);

		PowerFist		&operator=(PowerFist const &rhs);

		virtual void	attack(void) const;
};
#endif
