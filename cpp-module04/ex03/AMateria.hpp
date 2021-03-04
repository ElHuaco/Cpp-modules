/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:43:42 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/04 15:56:51 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>

class	AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		virtual ~AMateria(void);

		AMateria		&operator=(AMateria const &rhs);

		std::string const	&getType(void) const;
		unsigned int		getXP(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;
	
	private:
		AMateria(void);
		unsigned int		_xp;
		std::string	const	_type;
};
#endif
