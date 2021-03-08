/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Choppa.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:34:12 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/08 09:34:33 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOPPA_HPP
# define CHOPPA_HPP

# include "AWeapon.hpp"

class	Choppa : public AWeapon
{
	public:
		Choppa(void);
		Choppa(Choppa const &rhs);
		virtual			~Choppa(void);

		Choppa		&operator=(Choppa const &rhs);

		virtual void	attack(void) const;
};
#endif
