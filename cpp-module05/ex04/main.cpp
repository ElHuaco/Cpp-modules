/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 13:39:40 by alejandro        ###   ########.fr       */
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
	A1.demote();
	A1.demote();
	std::cout << A1 << std::endl;
	A2.promote();
	A2.promote();
	std::cout << A2 << std::endl;
	std::cout << std::endl;	
	Intern	someRandomIntern;

	OfficeBlock		ob(&someRandomIntern, &A1, &A2);

	//TODO: un ejemplo para cada uno de los 5 exceptions
	try
	{
		ob.doBureaucracy("shrubbery creation", "Venus");
	}
	catch (Intern::InternDidNotFindException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::FormAlreadySignedException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::FormNotSignedException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
