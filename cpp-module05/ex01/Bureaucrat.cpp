/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:00:10 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 18:56:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

void				Bureaucrat::signForm(Form &form) const
{
	bool	canSign = true;

	try
	{
		form.beSigned(*this);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << this->_name << " Grade (" << this->_grade << ")";
		std::cout << " could not sign " << form.getName();
		std::cout << " (s.g. " << form.getGradeSign() << ", e.g " << form.getGradeExec() << ") ";
		std::cout << e.what() << std::endl;
		canSign = false;
	}
	catch (Form::FormAlreadySignedException &e)
	{
		std::cout << this->_name << " Grade (" << this->_grade << ")";
		std::cout << " could not sign " << form.getName();
		std::cout << " (s.g. " << form.getGradeSign() << ", e.g " << form.getGradeExec() << ") ";
		std::cout << e.what() << std::endl;
		canSign = false;
	}
	if (canSign)
	{
		std::cout << this->_name << " Grade (" << this->_grade << ")";
		std::cout << " signs " << form.getName();
		std::cout << " (s.g. " << form.getGradeSign() << ", e.g " << form.getGradeExec() << ").";
		std::cout << std::endl;
		form.setSigned(true);
	}
	return;
}

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
