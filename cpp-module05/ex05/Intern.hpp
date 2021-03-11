/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:05:25 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 12:31:33 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern(void);
		~Intern(void);

		Form		*makeForm(std::string const &formName, std::string const &target);

		class InternDidNotFindException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

	private:
		Intern(Intern const &other);
		Intern		&operator=(Intern const &rhs);
};
#endif
