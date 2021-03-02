/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:12:09 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/02 09:33:21 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScravTrap : public ClapTrap
{
	public:
		ScravTrap(void);
		ScravTrap(std::string name);
		ScravTrap(ScravTrap const &rhs);
		~ScravTrap(void);

		ScravTrap	&operator=(ScravTrap const &rhs);

		void		challengeNewcomer(std::string const &target);
		void		setInitialValues(void);

	private:
		static std::string	_funny_challenges[5];
};
#endif
