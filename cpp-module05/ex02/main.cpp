/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 11:58:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	std::cout << "==========Exceptions on executions=============" << std::endl;
	ShrubberyCreationForm	S1("Marte");
	A2.executeForm(S1);
	A2.signForm(S1);
	A1.executeForm(S1);
	A2.executeForm(S1);
	std::cout << std::endl;	
	RobotomyRequestForm		R1("Bender");
	A2.executeForm(R1);
	A2.signForm(R1);
	A1.executeForm(R1);
	A2.executeForm(R1);
	A2.executeForm(R1);
	std::cout << std::endl;	
	PresidentialPardonForm	P1("Buen Ladrón");
	A2.executeForm(P1);
	A2.signForm(P1);
	A1.executeForm(P1);
	A2.executeForm(P1);
	std::cout << std::endl;	
	return (0);
}
