/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:00:10 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 10:52:10 by alejandro        ###   ########.fr       */
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
	if (form.getGradeSign() < this->_grade)
		throw Bureaucrat::GradeTooLowException();
	else if (form.isSigned() == true)
		throw Form::FormAlreadySignedException();
	std::cout << this->_name << " signs " << form.getName() << "." << std::endl;
	form.setSigned(true);
	return;
}

void				Bureaucrat::executeForm(Form const &form) const
{
	bool	canExec = true;

	try
	{
		form.checkExec(*this);
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << this->_name << " could not execute " << form.getName();
		std::cout << ". " << e.what() << std::endl;
		canExec = false;
	}
	catch (Form::FormNotSignedException & e)
	{
		std::cout << this->_name << " could not execute " << form.getName();
		std::cout << ". " << e.what() << std::endl;
		canExec = false;
	}
	if (canExec)
	{
		std::cout << this->_name << " executes " << form.getName() << ".";
		std::cout << std::endl;
		form.execute(*this);
	}
	return;
}

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
