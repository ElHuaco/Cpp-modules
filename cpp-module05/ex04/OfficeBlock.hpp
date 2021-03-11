/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:10:28 by alejandro         #+#    #+#             */
/*   Updated: 2021/03/11 13:25:15 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Form.hpp"
# include "Bureaucrat.hpp"

class	OfficeBlock
{
	public:
		OfficeBlock(void);
		OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
		~OfficeBlock(void);

		void		setIntern(Intern *intern);
		void		setSigner(Bureaucrat *signer);
		void		setExecutor(Bureaucrat *executor);

		void		doBureaucracy(std::string const &name, std::string const &target);

	private:
		OfficeBlock(OfficeBlock const &other);
		OfficeBlock		&operator=(OfficeBlock const &rhs);
		Intern		*_intern;
		Bureaucrat	*_signer;
		Bureaucrat	*_executor;
};
#endif
