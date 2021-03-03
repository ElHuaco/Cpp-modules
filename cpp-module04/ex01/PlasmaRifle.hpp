/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:23:52 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/03 11:26:54 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &rhs);
		virtual			~PlasmaRifle(void);

		PlasmaRifle		&operator=(PlasmaRifle const &rhs);

		virtual void	attack(void) const;
};
#endif
