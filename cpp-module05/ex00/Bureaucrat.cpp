/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:00:10 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 10:03:01 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
	_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return;
}

char const		*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return("Error: Grade is too high.");
}

char const		*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return("Error: Grade is too low.");
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::promote(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();	
	this->_grade -= 1;
	return;
}

void				Bureaucrat::demote(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade += 1;
	return;
}

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
