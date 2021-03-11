/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:54:49 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/10 12:32:49 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class		Form;

class		Bureaucrat
{
	public:
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat(void);

		std::string const	getName(void) const;
		int					getGrade(void) const;

		void				promote(void);
		void				demote(void);

		void				signForm(Form &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

	private:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat		&operator=(Bureaucrat const &rhs);
		std::string const	_name;
		int					_grade;
};

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &rhs);

# include "Form.hpp"
#endif
