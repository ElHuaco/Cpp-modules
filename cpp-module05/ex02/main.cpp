/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/10 19:25:32 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	std::cout << "===========Exceptions on creation==============" << std::endl;
	Bureaucrat		A1("joe", 148);
	Bureaucrat		A2("genny", 3);
	Bureaucrat		E1("trumann", -213);
	Bureaucrat		E2("trumann", 2313);
	std::cout << std::endl;
	
	std::cout << "==========Exceptions on promotions=============" << std::endl;
	std::cout << A1 << std::endl;
	A1.demote();
	std::cout << A1 << std::endl;
	A1.demote();
	std::cout << A1 << std::endl;
	A1.demote();
	std::cout << A1 << std::endl;
	std::cout << std::endl;
	std::cout << A2 << std::endl;
	A2.promote();
	std::cout << A2 << std::endl;
	A2.promote();
	std::cout << A2 << std::endl;
	A2.promote();
	std::cout << A2 << std::endl;
	std::cout << std::endl;	
	std::cout << "===========Exceptions on creation==============" << std::endl;
	Form			F1("Testamento", 123, 112);
	Form			E3("lololo", -10, 29);
	Form			E4("lololo", 10, -29);
	Form			E5("lololo", 1000, 29);
	Form			E6("lololo", 10, 2900);
	std::cout << std::endl;	
	std::cout << "===========Exceptions on signings==============" << std::endl;

	std::cout << F1 << std::endl;
	A1.signForm(F1);
	std::cout << std::endl;	
	std::cout << F1 << std::endl;
	A2.signForm(F1);
	std::cout << std::endl;	
	std::cout << F1 << std::endl;
	A2.signForm(F1);
	std::cout << std::endl;	
	return (0);
}
