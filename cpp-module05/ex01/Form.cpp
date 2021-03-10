/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:06:36 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/10 12:49:39 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form(void)
{
	return;
}

Form::Form(std::string const &name, int const gradeSign, int const gradeExec) :
	_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	try
	{
		if ((gradeSign < 1) || (gradeExec < 1))
			throw Bureaucrat::GradeTooHighException();
		else if ((gradeSign > 150) || (gradeExec > 150))
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
		this->~Form();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
		this->~Form();
	}
	return;
}

const char		*Form::FormAlreadySignedException::what(void) const throw()
{
	return ("Error: form is already signed.");
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool				Form::isSigned(void) const
{
	return (this->_isSigned);
}

int const			Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int const			Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void				Form::setSigned(bool answer)
{
	this->_isSigned = answer;
	return;
}

void			Form::beSigned(Bureaucrat const &signer)
{
	signer.signForm(*this);
	return;
}

std::ostream		&operator<<(std::ostream &os, Form const &rhs)
{
	os << "Form " << rhs.getName() << "(" << rhs.getGradeSign();
	os << " ," << rhs.getGradeExec() << ") is signed? -> ";
	os << rhs.isSigned();
	return (os);
}
