/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:45:22 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 11:48:13 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int		random_number = rand() % 2;

	std::cout << "* DRILLING NOISES *" << std::endl;
	if (random_number)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " has been robotomized unsuccessfully." << std::endl;
	return;
}
