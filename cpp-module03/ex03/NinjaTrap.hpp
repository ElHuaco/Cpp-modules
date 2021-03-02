/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:03:19 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 12:11:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "ScravTrap.hpp"
# include "FragTrap.hpp"

class	NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &rhs);
		~NinjaTrap(void);

		NinjaTrap	&operator=(NinjaTrap const &rhs);

		void		ninjaShoebox(NinjaTrap &target);	
		void		ninjaShoebox(ScravTrap &target);	
		void		ninjaShoebox(FragTrap &target);	
		void		ninjaShoebox(ClapTrap &target);	

		void		setInitialValues(void);
};
#endif
