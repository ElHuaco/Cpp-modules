/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 18:57:01 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	Bureaucrat		A1("joe", 148);
	Bureaucrat		A2("genny", 3);
	std::cout << "===========Exceptions on creation==============" << std::endl;
	Form			F1("Testamento", 123, 112);
	try
	{
		Form			E3("lololo", -10, 29);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form			E4("lololo", 10, -29);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form			E5("lololo", 1000, 29);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form			E6("lololo", 10, 2900);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;	
	std::cout << "===========Exceptions on signings==============" << std::endl;
	std::cout << F1 << std::endl;
	try
	{
		A1.signForm(F1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << A1.getName() << " cannot sign " << F1.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;	
	std::cout << F1 << std::endl;
	A2.signForm(F1);
	std::cout << std::endl;	
	std::cout << F1 << std::endl;
	try
	{
		A2.signForm(F1);
	}
	catch (Form::FormAlreadySignedException &e)
	{
		std::cout << A2.getName() << " cannot sign " << F1.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;	
	return (0);
}
