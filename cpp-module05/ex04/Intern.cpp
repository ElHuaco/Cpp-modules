/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:08:58 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 16:25:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return;
}

Intern::~Intern(void)
{
	return;
}

char const	*Intern::InternDidNotFindException::what(void) const throw()
{
	return ("Error: the poor intern did not find the requested form.");
}

static Form	*CreateShrub(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static Form	*CreateRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*CreatePresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form		*Intern::makeForm(std::string const &name, std::string const &target)
{
	typedef Form	*(*creator_arr)(std::string const &target);

	creator_arr		creator_arr_inst[] = {&CreateShrub, &CreateRobotomy,
		&CreatePresidential};
	std::string form_str[] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
	for (int i = -1; i < 3; ++i)
		if (name == form_str[i])
		{
			std::cout << "The intern found a form for " << name << std::endl;
			return (creator_arr_inst[i](target));
		}
	throw InternDidNotFindException();
}
