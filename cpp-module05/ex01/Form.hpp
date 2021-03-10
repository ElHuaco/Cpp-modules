/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:54:27 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/10 12:44:48 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string const &name, int const gradeSign, int const gradeExec);
		~Form(void);

		std::string const		getName(void) const;
		bool					isSigned(void) const;
		int const				getGradeSign(void) const;
		int const				getGradeExec(void) const;
		void					setSigned(bool answer);

		void					beSigned(Bureaucrat const &signer);

		class	FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Form(void);
		Form &operator=(Form const &rhs);
		std::string const		_name;
		bool					_isSigned;
		int const				_gradeSign;
		int const				_gradeExec;
};

std::ostream	&operator<<(std::ostream &os, Form const &rhs);
#endif
