/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:22:10 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 11:49:25 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string const &target);
		virtual ~RobotomyRequestForm(void);

		virtual void		execute(Bureaucrat const &executor) const;

	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		std::string const	_target;
};
#endif
