/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:25:27 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 13:38:31 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) : _intern(nullptr), _signer(nullptr),
	_executor(nullptr)
{
	return;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor) :
	_intern(intern), _signer(signer), _executor(executor)
{
	return;
}

OfficeBlock::~OfficeBlock(void)
{
	return;
}

void		OfficeBlock::setIntern(Intern *intern)
{
	this->_intern = intern;
	return;
}

void		OfficeBlock::setSigner(Bureaucrat *signer)
{
	this->_signer = signer;
	return;
}

void		OfficeBlock::setExecutor(Bureaucrat *executor)
{
	this->_executor = executor;
	return;
}

void		OfficeBlock::doBureaucracy(std::string const &name, std::string const &target)
{
	if ((this->_intern == nullptr) || (this->_signer == nullptr)
		|| (this->_executor == nullptr))
		return;
	Form	*temp;
	temp = this->_intern->makeForm(name, target);
	this->_signer->signForm(*temp);
	this->_executor->executeForm(*temp);
	delete temp;
	return;
}
