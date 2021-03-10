/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:00:10 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/10 12:50:28 by alejandro        ###   ########.fr       */
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
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
		this->~Bureaucrat();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
		this->~Bureaucrat();
	}
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
	try
	{
		if (this->_grade == 1)
			throw GradeTooHighException();
	}	
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	this->_grade -= 1;
	return;
}

void				Bureaucrat::demote(void)
{
	try
	{
		if (this->_grade == 150)
			throw GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	this->_grade += 1;
	return;
}

void				Bureaucrat::signForm(Form &form) const
{
	try
	{
		if (form.getGradeSign() < this->_grade)
			throw Bureaucrat::GradeTooLowException();
		else if (form.isSigned() == true)
			throw Form::FormAlreadySignedException();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		return;
	}
	catch (Form::FormAlreadySignedException &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << this->_name << " signs " << form.getName() << "." << std::endl;
	form.setSigned(true);
	return;
}

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
