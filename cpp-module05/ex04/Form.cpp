/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:06:36 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 18:59:27 by alejandro        ###   ########.fr       */
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
	if ((gradeSign < 1) || (gradeExec < 1))
		throw Bureaucrat::GradeTooHighException();
	else if ((gradeSign > 150) || (gradeExec > 150))
		throw Bureaucrat::GradeTooLowException();
	return;
}

const char		*Form::FormAlreadySignedException::what(void) const throw()
{
	return ("Error: form is already signed. Cannot sign again.");
}

const char		*Form::FormNotSignedException::what(void) const throw()
{
	return ("Error: form is not signed. Cannot execute.");
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
	if (this->_gradeSign < signer.getGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->_isSigned == true)
		throw Form::FormAlreadySignedException();
	return;
}

void			Form::checkExec(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw Bureaucrat::GradeTooLowException();
	else if (this->isSigned() == false)
		throw Form::FormNotSignedException();
	return;
}

std::ostream		&operator<<(std::ostream &os, Form const &rhs)
{
	os << "Form " << rhs.getName() << "(" << rhs.getGradeSign();
	os << " ," << rhs.getGradeExec() << ") is signed? -> ";
	os << rhs.isSigned();
	return (os);
}
