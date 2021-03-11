/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 16:26:54 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int		main(void)
{
	srand(time(NULL));
	Bureaucrat		A1("joe", 148);
	Bureaucrat		A2("genny", 3);
	Intern	someRandomIntern;

	OfficeBlock		ob(&someRandomIntern, &A1, &A2);

	std::cout << "======Exception on intern form creation=======" << std::endl;
	try
	{
		ob.doBureaucracy("shrubberyyyyyyy creation", "Venus");
	}
	catch (Intern::InternDidNotFindException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "==========Exception on signer grade==========" << std::endl;
	try
	{
		ob.doBureaucracy("shrubbery creation", "Venus");
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=========Exception on executor grade========" << std::endl;
	while (A1.getGrade() > 25)
		A1.promote();
	while (A2.getGrade() <= 5)
		A2.demote();
	try
	{
		ob.doBureaucracy("presidential pardon", "Pepe");
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "================Correct Use================" << std::endl;
	ob.doBureaucracy("robotomy request", "Bender");
	return (0);
}
