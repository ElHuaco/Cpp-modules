/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 10:04:41 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	std::cout << "===========Exceptions on creation==============" << std::endl;
	Bureaucrat		A1("joe", 148);
	Bureaucrat		A2("genny", 3);
	try
	{
		Bureaucrat		E1("trumann", -213);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat		E2("trumann", 2313);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "==========Exceptions on promotions=============" << std::endl;
	std::cout << A1 << std::endl;
	A1.demote();
	std::cout << A1 << std::endl;
	A1.demote();
	std::cout << A1 << std::endl;
	try
	{
		A1.demote();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << A1 << std::endl;
	std::cout << std::endl;
	std::cout << A2 << std::endl;
	A2.promote();
	std::cout << A2 << std::endl;
	A2.promote();
	std::cout << A2 << std::endl;
	try
	{
		A2.promote();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << A2 << std::endl;
	return (0);
}
