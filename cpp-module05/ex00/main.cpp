/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:30:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/10 11:49:20 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	return (0);
}
