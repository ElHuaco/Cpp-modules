/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:52:36 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 11:53:29 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return;
}
